*This project has been created as part of the 42 curriculum by qcyril-a.*

# miniRT

## Description

`miniRT` is a ray tracing project from the 42 curriculum.

The goal of the project is to create a small ray tracer written in C. The program reads a scene from a `.rt` file, generates one ray for each pixel of a window, calculates intersections with objects, applies lighting, and displays the final image using MiniLibX.

The project currently includes the parsing and object-management foundations for:

- Spheres;
- Planes;
- Cylinders;
- Cameras;
- Point lights;
- Ambient lighting.

The main objective is to understand how a basic ray tracer works, including 3D vectors, ray-object intersections, surface normals, lighting, and image generation.

## Features

The current implementation supports:

- Ambient lighting;
- One point light;
- One camera;
- Spheres;
- Planes;
- Finite cylinders with caps;
- Multiple objects of the same or different types;
- Primary-ray intersections;
- Surface normals;
- Diffuse lighting;
- Hard shadows;
- ESC and window-close handling;
- Basic scene validation.

The scene is rendered once when the program starts. The object positions and orientations are specified in the `.rt` file; there are no interactive object transformations.

## Compilation

The project requires:

- Linux;
- `cc` or `gcc`;
- `make`;
- X11 development libraries;
- MiniLibX Linux;
- The included Libft.

On Debian or Ubuntu:

```bash
sudo apt update
sudo apt install build-essential libx11-dev libxext-dev libbsd-dev
```

Compile the project from the `minirtNew` directory:

```bash
make
```

The executable is called:

```text
miniRT
```

Other Makefile commands:

```bash
make clean
make fclean
make re
make sanitize
```

## Usage

The program accepts exactly one scene file:

```bash
./miniRT scene.rt
```

The scene file must have the `.rt` extension.

The program opens an 800×600 MiniLibX window and renders the scene.

The program can be closed by:

- Pressing `ESC`;
- Clicking the window close button.

## Scene file format

A scene contains one element per line. Values are separated by spaces.

Vectors and colors use comma-separated components:

```text
x,y,z
```

Full-line comments beginning with `#` and empty lines are ignored.

Inline comments are not supported.

### Ambient lighting

```text
A ratio R,G,B
```

Example:

```text
A 0.2 255,255,255
```

- `ratio` is the ambient intensity and should be between `0.0` and `1.0`;
- `R,G,B` is the ambient color;
- Exactly one ambient-light declaration is required.

### Camera

```text
C x,y,z nx,ny,nz FOV
```

Example:

```text
C 0,0,-5 0,0,1 70
```

- `x,y,z` is the camera position;
- `nx,ny,nz` is the camera orientation;
- `FOV` is the field of view in degrees;
- The direction vector must not be zero;
- The implementation normalizes the camera direction;
- Exactly one camera declaration is required.

### Point light

```text
L x,y,z ratio R,G,B
```

Example:

```text
L -2,5,-3 0.7 255,255,255
```

- `x,y,z` is the light position;
- `ratio` is the light intensity and should be between `0.0` and `1.0`;
- `R,G,B` is the light color;
- The current implementation supports one point light.

### Sphere

```text
sp x,y,z diameter R,G,B
```

Example:

```text
sp 0,0,0 2 255,0,0
```

- `x,y,z` is the sphere center;
- `diameter` must be positive;
- The intersection code uses:

```text
radius = diameter / 2
```

### Plane

```text
pl x,y,z nx,ny,nz R,G,B
```

Example:

```text
pl 0,-2,0 0,1,0 0,255,100
```

- `x,y,z` is a point belonging to the plane;
- `nx,ny,nz` is the plane normal;
- The normal must not be the zero vector;
- The implementation normalizes the plane normal.

### Cylinder

```text
cy x,y,z nx,ny,nz diameter height R,G,B
```

Example:

```text
cy 2,0,1 0,1,0 1.0 2.0 0,100,255
```

- `x,y,z` is the center of the cylinder;
- `nx,ny,nz` is the cylinder axis;
- `diameter` must be positive;
- `height` must be positive;
- The axis is normalized;
- The cylinder is finite;
- The cylinder has two circular caps;
- The cylinder extends by `height / 2` on each side of its center along its axis.

## Rendering pipeline

For each pixel:

1. The pixel coordinates are converted to normalized screen coordinates.
2. A camera basis is built:
   - `forward`: normalized camera direction;
   - `right`: perpendicular horizontal direction;
   - `up`: perpendicular vertical direction.
3. A ray is generated from the camera position through the center of the pixel.
4. The ray is tested against every object.
5. The closest positive intersection is selected.
6. The intersection point and surface normal are calculated.
7. Ambient lighting, diffuse lighting, and shadows are calculated.
8. The final RGB value is written to the image buffer.

The program uses one ray per pixel and does not currently implement anti-aliasing, reflections, refractions, or specular highlights.

## Mathematical calculations

### Vector operations

A vector is represented as:

```text
v = (x, y, z)
```

Addition:

```text
a + b = (ax + bx, ay + by, az + bz)
```

Subtraction:

```text
a - b = (ax - bx, ay - by, az - bz)
```

Scaling:

```text
k × a = (kax, kay, kaz)
```

Dot product:

```text
a · b = ax × bx + ay × by + az × bz
```

Cross product:

```text
a × b =
(
    ay × bz - az × by,
    az × bx - ax × bz,
    ax × by - ay × bx
)
```

Length:

```text
|v| = sqrt(x² + y² + z²)
```

Normalization:

```text
normalize(v) = v / |v|
```

Zero vectors must not be normalized. The parser rejects zero direction vectors for cameras, planes, and cylinders.

### Ray equation

A ray is defined by an origin `O` and a direction `D`:

```text
R(t) = O + tD
```

The renderer considers only intersections with a positive distance:

```text
t > EPSILON
```

### Sphere intersection

For a sphere with center `C` and radius `r`:

```text
|P - C|² = r²
```

Substituting the ray equation produces:

```text
at² + bt + c = 0
```

with:

```text
a = D · D
b = 2 × (O - C) · D
c = (O - C) · (O - C) - r²
```

The discriminant is:

```text
Δ = b² - 4ac
```

If `Δ < 0`, there is no intersection.

The two possible distances are:

```text
t1 = (-b - sqrt(Δ)) / (2a)
t2 = (-b + sqrt(Δ)) / (2a)
```

The closest positive value is selected.

### Plane intersection

A plane is represented by a point `P0` and a normal `N`.

The intersection distance is:

```text
t = ((P0 - O) · N) / (D · N)
```

If `D · N` is close to zero, the ray is parallel to the plane and there is no intersection.

### Cylinder intersection

The cylinder calculation removes the component of the ray and the ray origin that is parallel to the cylinder axis.

For a normalized axis `A`:

```text
Dperp = D - (D · A)A
```

For the relative origin:

```text
Operp = (O - C) - ((O - C) · A)A
```

The side intersection is calculated using:

```text
a = Dperp · Dperp
b = 2 × (Dperp · Operp)
c = Operp · Operp - r²
```

The resulting intersections are accepted only when their position along the cylinder axis lies inside the finite height:

```text
-height / 2 <= projection <= height / 2
```

The two caps are tested separately as circular disks. The closest valid intersection between the side and the caps is selected.

### Surface normals

Sphere:

```text
N = normalize(P - C)
```

Plane:

```text
N = normalize(plane_normal)
```

Cylinder side:

```text
N = normalize((P - C) - ((P - C) · A)A)
```

Cylinder caps:

```text
N = A
```

or:

```text
N = -A
```

depending on which cap was hit.

### Lighting

The object color and light color are multiplied component by component.

Ambient contribution:

```text
ambient = object_color × ambient_color × ambient_ratio
```

For diffuse lighting:

```text
L = normalize(light_position - intersection_point)
diffuse_factor = max(0, N · L)
```

The diffuse contribution is:

```text
diffuse =
    object_color
    × light_color
    × light_ratio
    × diffuse_factor
```

If another object intersects the ray from the intersection point to the light before the light is reached, the point is considered shadowed and only the ambient contribution is used.

The final color is clamped to the range:

```text
0 to 255
```

## Example scene

```text
A 0.2 255,255,255
C 0,0,-5 0,0,1 70
L -2,5,-3 0.7 255,255,255

sp 0,0,0 2 255,0,0
pl 0,-2,0 0,1,0 0,255,100
cy 2,0,1 0,1,0 1.0 2.0 0,100,255
```

## Current limitations

The current implementation does not provide:

- Multiple point lights;
- Specular lighting;
- Reflections;
- Refractions;
- Textures;
- Anti-aliasing;
- Interactive object movement or rotation;
- Interactive camera movement;
- A configurable window size;
- Complete window-resize redraw handling;
- Inline comments in `.rt` files.

Input validation should also be strengthened for all numerical values, especially RGB components.

## Memory management

Scene objects, image structures, MiniLibX resources, and dynamically allocated parser buffers must be released before termination.

The project should be tested with tools such as:

```bash
valgrind --leak-check=full ./miniRT scene.rt
```

or AddressSanitizer:

```bash
make sanitize
```

## Credits

