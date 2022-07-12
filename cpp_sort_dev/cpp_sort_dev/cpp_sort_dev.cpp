// cpp_sort_dev.cpp: 定義應用程式的進入點。
//

#include "cpp_sort_dev.h"
#include "tracker.h"
// include numpy object array api
#include <numpy/arrayobject.h>
#include <map>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	Tracker* tracker = new Tracker(3, 0.3);

	return 0;
}
