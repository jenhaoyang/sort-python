# SORT-PYTHON

Python module bindings for SORT algorithm (Simple, Online, and Realtime Tracking) implemented in C++, with the goal of being fast and easy to use. Tracker is based on this [repo](https://github.com/yasenh/sort-cpp).

# Installation

Before you can install the package, you need to install the following dependencies:

## for Ubuntu user
```bash
$ sudo apt install libopencv-dev
$ sudo apt install libeigen3-dev
```
Make sure pip is upgraded to last version:
```bash
$ pip install pip --upgrade
```

# for Windows User (For build from source)
(Install OpenCV)[https://docs.opencv.org/4.6.0/d3/d52/tutorial_windows_install.html]  
(Install Eigen3)[https://gitlab.com/libeigen/eigen/-/blob/master/INSTALL#L19] wihtout the "make install" step
Set environment variable for cmake to find packege
* Eigen3_ROOT
* OpenCV_ROOT



Then you can install the package using:

```bash
$ pip install sort-tracker
```

or
    
```bash
$ git clone https://github.com/MrGolden1/sort-python.git
$ cd sort-python
$ pip install .
```

# Usage

    
```python
import sort
# Create a tracker with max_age = 5, min_hits = 3 and iou_threshold = 0.2
# Default values are max_age = 3, min_hits = 1 and iou_threshold = 0.3
tracker = sort.SORT(max_age=5, min_hits=3, iou_threshold=0.2)
```

## Methods:

Two main methods are available named `run` and `get_tracks` and you can specify format of input and output bounding boxes as follows:

```python
# format (int):
#    0: [xmin, ymin, w, h]
#    1: [xcenter, ycenter, w, h]
#    2: [xmin, ymin, xmax, ymax]
```

defaulf format is 0.

### `run`

`run` method takes an array of bounding boxes and format, and then performs tracking.

```python
# Input:
#   bounding_boxes: a numpy array of bounding boxes with its confidence and class id [n, 6]
#   format: format of bounding boxes (int)
import numpy as np
bounding_boxes = np.array([[10, 10, 20, 20, 90, 1], [30, 30, 40, 40, 70, 2]])
tracker.run(bounding_boxes, 0)
```

### `get_tracks`

`get_tracks` method returns a array of tracks.

```python
# Input:
#   format: format of bounding boxes (int)
# Output:
#   tracks: a numpy array of tracks [n, 7] where n is the number of tracks
#       and 7 is (id, ..., ..., ..., ..., confidence, class_id) where id is the track id and ... is the bounding box in the specified format
tracks = tracker.get_tracks(0)
```

# Demo

![demo](demo.gif)

`Author: MrGolden1`

`Email: ali.zarrinzadeh@gmail.com`
