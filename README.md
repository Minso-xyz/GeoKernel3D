# GeoKernel3D 👾
 
GeoKernel3D is a personal C++ experiment exploring the foundation of:
 
- 3D Computational Geometry
- Graphics Mathematics
- CAD Kernel Concepts
- B-Rep data structures
- STEP-Based CAD Representations


The goal is to build geometry and topology structures from scratch while gradually working toward STEP file understanding and CAD data processing.
 
## Current Features
### Vector3D
- Length
- Unit Vector
- Normalize
- Dot Product
- Cross Product
- Operator Overloading (+, -, *, /)
 
### Point3D
- VectorTo
- DistanceTo
- Translate
- Point + Vector
- Point - Vector
 
### Line3D
- Length
- Direction
- MidPoint
- Reverse
- Point Projection (WIP)

### Curves
- Bezier Curve
  - Linear
  - Quadratic
  - Cubic
  - Quartic
    
- B-Spline
  - Control Points
  - Knot Vector
  - Degree
  - Parameter Range

### Surfaces & Plane
- Plane
  - DistanceTo
  - ProjectPoint
  - Contains
  - Plane Equation
  - Line-Plane Intersection (WIP)

### Mesh & Topology
- Triangle
  - Area
  - Normal
    
- Mesh
  - Area
  - BoundingBox

- B-Rep
  - Vertex
  - Edge
  - Face
  - Entity Count

### Transformations
- Matrix4x4
  - Translation
  - Rotation
  - Scale
  - Mirror
  - Transform

## Future Experiments
- NURBS Curves
- Ray
- Additional Intersection Algorithms
- STEP File Parsing
- STEP Entity Mapping
- B-Rep Relationships
- Surface Representation
- OPENGL Viewer

## Notes
This is an experimental project.

The focus is on exploration, understanding, and implementation rather than performance, optimization, or production-quality CAD functionality.
