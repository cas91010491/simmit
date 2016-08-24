FROM chemiskyy/smartplus

#tweak boost
RUN cp /usr/lib/libboost_numpy.so /usr/lib/x86_64-linux-gnu/libboost_numpy.so && \
    rm /usr/lib/libboost_numpy.so

RUN mkdir /notebooks && chmod -R 777 /notebooks

#install simmit
RUN export SIMMIT_URL=https://github.com/chemiskyy/simmit.git && \
    export SIMMIT_NAME=simmit && \
    export SIMMIT_SOURCE_DIR=${PREFIX}/source/simmit && \
    export SIMMIT_SMART_SOURCE_DIR=${SIMMIT_SOURCE_DIR}/smartplus-builder && \
    export SIMMIT_SMART_BUILD_DIR=${PREFIX}/build/simmit/smartplus-builder && \
    cd ${PREFIX}/source && \
    git clone ${SIMMIT_URL} ${SIMMIT_NAME} && \
    mkdir -p ${SIMMIT_SMART_BUILD_DIR} && \
    cd ${SIMMIT_SMART_BUILD_DIR} && \
    cmake \
    -D CMAKE_INSTALL_PREFIX=/usr \
    ${SIMMIT_SMART_SOURCE_DIR} && \
    make && \
    make test && \
    make install && \
    cp ${SIMMIT_SMART_BUILD_DIR}/lib/smartplus.so ${SIMMIT_SOURCE_DIR}/python-setup/simmit/smartplus.so && \
    cp ${SIMMIT_SMART_BUILD_DIR}/lib/identify.so ${SIMMIT_SOURCE_DIR}/python-setup/simmit/identify.so && \
    cp -R ${SIMMIT_SOURCE_DIR}/Examples /notebooks && \
    cd ${SIMMIT_SOURCE_DIR}/python-setup && \
    python ${SIMMIT_SOURCE_DIR}/python-setup/setup.py install && \
    rm -rf ${SIMMIT_SOURCE_DIR} && \
    rm -rf ${SIMMIT_SMART_BUILD_DIR}

ENV PYTHONPATH=/usr/local/lib/python2.7/dist-packages/:${PYTHONPATH}

ENV SHELL /bin/bash
ENV NB_USER jovyan
ENV NB_UID 1000

RUN useradd -m -s /bin/bash -N -u $NB_UID $NB_USER && \
    mkdir /home/$NB_USER/.jupyter && \
    mkdir /home/$NB_USER/.local && \
    mkdir /home/$NB_USER/notebooks && \
    chown -R $NB_USER:users /home/$NB_USER

EXPOSE 8888
WORKDIR /notebooks
VOLUME /notebooks
ENTRYPOINT ["tini", "--"]
CMD ["start-notebook.sh"]

COPY docker/start-notebook.sh /usr/local/bin/
COPY docker/jupyter_notebook_config.py /home/$NB_USER/.jupyter/
COPY docker/jupyter_nbconvert_config.py /home/$NB_USER/.jupyter/
RUN chown -R $NB_USER:users /home/$NB_USER/.jupyter