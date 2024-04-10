#!/bin/bash -e

# Example pipeline to acquire a ZED X One 4K stream at 15 FPS and render it displaying the current FPS using default values for each parameter

gst-launch-1.0 zedxonesrc camera-resolution=2 camera-fps=60 ! queue ! autovideoconvert ! queue ! fpsdisplaysink
