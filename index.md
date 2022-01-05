# Skity: 2D Vector Graphic Library

## Introduction

Skity is a 2D vector graphic render library writing in c++. The API follows the same pattern as [Skia](https://skia.org/) and implements the backend rendering by myself. Currently it can run on OpenGL and Vulkan context.

### Brief Overview

To use Skity just include the header file in sources code.

```c++
#include <skity/skity.hpp>
```

#### Initialization

The first thing need to do is crerating a `skity::Canvas` instance.

```c++
auto canvas =
        skity::Canvas::MakeHardwareAccelationCanvas(width, height, density, ctx);
```

- The first two parameters `width` and `height` are the size information for target which is canvas will render into.
- The third parameter is the pixel density of the current phisycal device.
- The last parameter is depends on what gpu context is used. For OpenGL context, just pass a `skity::GPUContext*` and pass a function pointer for [OpenGL Loading Function](https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions), since Skity not link OpenGL library in compile time, it will use this function to load needed functions in runtime.

#### Basic Usage

##### Shapes

```c++
// paint controls the color and style when geometry is rendered,
skity::Paint paint;
paint.setStyle(skity::Paint::kFill_Style);
paint.setColor(skity::ColorSetRGB(0x42, 0x85, 0xF4));
// create a rectangle shape
auto rect = skity::Rect::MakeXYWH(10, 10, 100, 160);
// draw a rounded rectangle
canvas->drawRoundRect(rect, 10, 10, paint);
```
The result of above code looks as follows:
<p align="center">
    <img src="images/rectangle.png" width="200" height="200" />
</p>

##### Paths
```c++
skity::Paint paint;
paint.setStyle(skity::Paint::kFill_Style);
paint.setColor(skity::ColorSetRGB(0x42, 0x85, 0xF4));

// create path
skity::Path path;
path.moveTo(199, 34);
path.lineTo(253, 143);
path.lineTo(374, 160);
path.lineTo(287, 244);
path.lineTo(307, 365);
path.lineTo(199, 309);
path.lineTo(97, 365);
path.lineTo(112, 245);
path.lineTo(26, 161);
path.lineTo(146, 143);
path.close();

canvas->drawPath(path, paint);
```
By using the Path, lines and Bezier curves can be drawn. And the code will render a star shape as follow:

<p align="center">
    <img src="images/fill_star.png" width="300" height="300" />
</p>

##### Stroke Bézier Curves
```c++
skity::Paint paint;
paint.setStyle(skity::Paint::kStroke_Style);
paint.setStrokeWidth(8);
paint.setColor(0xff4285F4);
paint.setStrokeCap(skity::Paint::kRound_Cap);

skity::Path path;
path.moveTo(10, 10);
path.quadTo(256, 64, 128, 128);
path.quadTo(10, 192, 250, 250);
canvas->drawPath(path, paint);
```
Paint can control line cap and stroke width, the above code shoud render a bezier curve like below:

<p align="center">
    <img src="images/stroke_curve.png" width="300" height="300" />
</p>

#### More Examples

Can find the example code under [example](https://github.com/RuiwenTang/Skity/tree/main/example) directory
