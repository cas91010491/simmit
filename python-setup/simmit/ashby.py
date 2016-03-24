# -*- coding: utf-8 -*-

import numpy as np
from scipy.spatial import ConvexHull
import matplotlib.pyplot as plt
from matplotlib.path import Path
import matplotlib.patches as patches
from matplotlib import rcParams
import math as m

def unit_vector(pt_a, pt_b):
    b_a = [pt_b[0]-pt_a[0],pt_b[1]-pt_a[1]]
    distance = m.sqrt(b_a[0]**2+b_a[1]**2)
    return np.array([b_a[0]*(1.0/distance),b_a[1]*(1.0/distance)])

def length(pt_a, pt_b):
    b_a = [pt_b[0]-pt_a[0],pt_b[1]-pt_a[1]]
    distance = m.sqrt(b_a[0]**2+b_a[1]**2)
    return distance      
           
def uv_2(uv1, uv2):
    b_a = [uv1[0]-uv2[0],uv1[1]-uv2[1]]
    distance = m.sqrt(b_a[0]**2+b_a[1]**2)
    return np.array([b_a[0]*(1.0/distance),b_a[1]*(1.0/distance)])

def poly_convexHull(points, color, coef_multi=0.1, rad=0.3, lw=2):
    """
    Plot the convex hull around a set of points as a 
    shaded polygon.
    """
    pt_env = points
    for i in range(0,len(points)):
        pt_env = np.append(pt_env, points[i] + (2.0*coef_multi*np.random.rand(10,2)-coef_multi)*points[i], axis=0)

    hull_env = ConvexHull(pt_env)
    hull_indices_env = hull_env.vertices

    u_v = np.zeros((len(hull_indices_env),2))
    
    verts = np.zeros((len(hull_indices_env),2))
    dist = np.zeros((len(hull_indices_env),2))
    
    for i in range(0,len(hull_indices_env)):
        verts[i] = pt_env[hull_indices_env[i]]
        u_v[i] = unit_vector(pt_env[hull_indices_env[i-1]], pt_env[hull_indices_env[i]]) 
        dist[i] = length(pt_env[hull_indices_env[i-1]], pt_env[hull_indices_env[i]])         

    verts2 = np.zeros((3*len(verts)+1,2))
    for i in range(0,len(hull_indices_env)-1):
        verts2[i*3] = verts[i] - u_v[i]*dist[i]*rad
        verts2[i*3+1] = verts[i]
        verts2[i*3+2] = verts[i] + u_v[i+1]*dist[i+1]*rad
    verts2[-4] = verts[-1] - u_v[-1]*dist[-1]*rad
    verts2[-3] = verts[-1]
    verts2[-2] = verts[-1] + u_v[0]*dist[0]*rad
    verts2[-1] = verts2[0]

#    for pt in pt_env:
#        plt.plot(pt[0], pt[1], 'ko')

#    for pt in points:
#        plt.plot(pt[0], pt[1], 'ro')

    codes = [Path.MOVETO,]
    for j in range(len(verts)):
        codes.extend([Path.CURVE3, Path.CURVE3, Path.LINETO,])
    #codes.append(Path.CURVE3)

    path = Path(verts2, codes)
    patch = patches.PathPatch(path, facecolor=color, lw=0, alpha=0.2)
    edge = patches.PathPatch(path, edgecolor=color, facecolor='none', lw=lw)
    plt.gca().add_patch(patch)
    plt.gca().add_patch(edge)
