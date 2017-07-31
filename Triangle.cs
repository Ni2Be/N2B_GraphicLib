using UnityEngine;
using System.Collections;
#if UNITY_EDITOR
using UnityEditor;
#endif
using System;

public class Triangle : MonoBehaviour
{
    public Vector3  p0_       = new Vector3(0.0f, 0.0f, 0.0f);
    public Vector3  p1_       = new Vector3(0.0f, 0.0f, 1.0f);
    public Vector3  p2_       = new Vector3(1.0f, 0.0f, 0.0f);
    public Vector3  p3_       = new Vector3(1.0f, 0.0f, 1.0f);

    MeshFilter      mesh_filter_;
    MeshRenderer    mesh_renderer_;
    Mesh            mesh_;

    float           time_counter_;

    public void OnDrawGizmos()
    {
        //Dots
        Gizmos.color        = Color.green;
        Gizmos.DrawSphere   (p0_, 0.1f);
        Gizmos.color        = Color.blue;
        Gizmos.DrawSphere   (p1_, 0.1f);
        Gizmos.color        = Color.red;
        Gizmos.DrawSphere   (p2_, 0.1f);
        Gizmos.color        = Color.cyan;
        Gizmos.DrawSphere   (p3_, 0.1f);


        //Lines
        Gizmos.color        = Color.cyan;
        Gizmos.DrawLine     (p0_, p1_);
        Gizmos.DrawLine     (p1_, p2_);
        Gizmos.DrawLine     (p2_, p0_);
        Gizmos.DrawLine     (p2_, p3_);
        Gizmos.DrawLine     (p1_, p3_);
    }


    public void Start()
    {
        CreateMesh();
    }

    public void Reset()
    {
        CreateMesh();
    }


    public void CreateMesh()
    {
        //MeshFilter init
        mesh_filter_            = GetComponent<MeshFilter>();
        if (mesh_filter_ == null)
            mesh_filter_        = gameObject.AddComponent<MeshFilter>();

        //MeshRenderer init
        mesh_renderer_          = GetComponent<MeshRenderer>();
        if (mesh_renderer_ == null)
            mesh_renderer_      = gameObject.AddComponent<MeshRenderer>();

        //Mesh init
        mesh_                   = new Mesh();
        Vector3[]     vertecies = new Vector3[4];
        vertecies[0]            = transform.TransformPoint(p0_);
        vertecies[1]            = transform.TransformPoint(p1_);
        vertecies[2]            = transform.TransformPoint(p2_);
        vertecies[3]            = transform.TransformPoint(p3_);
        
        int[]        vert_index = new int[6];
        vert_index[0]           = 0;
        vert_index[1]           = 1;
        vert_index[2]           = 2;
        
        vert_index[3]           = 3;
        vert_index[4]           = 2;
        vert_index[5]           = 1;
        
        mesh_.vertices          = vertecies;
        mesh_.triangles         = vert_index;
        
        mesh_filter_.sharedMesh = mesh_;
    }


    void Update()
    {
        time_counter_ += Time.deltaTime;
    }

#if UNITY_EDITOR
    [MenuItem("GameObject/3D Object/Trinangle")]
    public static void CreateTrinangle()
    {
        GameObject go               = new GameObject("Triangle");
        go.AddComponent<Triangle>();

    }
#endif
}
