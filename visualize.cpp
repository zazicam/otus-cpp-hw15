#include "png.hpp"

#include <touple> 

struct Point {
	double x;
	double y;
	int cluster;
}

int main(int argc, char *argv[])
{
	// Make sure that the output filename argument has been provided
	if (argc != 2) {
		fprintf(stderr, "Please specify output .png file\n");
		exit(1);
	}

	// read data
	vector<Point> points;	
	char sep; // separator
	Point point;
	while(cin>>point.x>>sep>>point.y>>sep>>point.cluster) {
		points.push_back(point);
	}

	// calculate range of data
	Point p = points[0]; 
	double min_x = p.x , min_y = p.y, max_x = p.x, max_y = p.y;
	for(const auto& p : points) {
		if(p.x < min_x) min_x = p.x;
		if(p.y < min_y) min_y = p.y;
		if(p.x > max_x) max_x = p.x;
		if(p.y > max_y) max_y = p.y;

	}

	int h = 1000;
	int w = 1000;
	Image image(w,h);

	for(int i=0;i<h;++i)
		for(int j=0;j<w;++j) {
			image.set_pixel(i,j, rgb{i,j,0});
		}

	for(int i=0;i<50;++i) {
		int x = rand()%w;
		int y = rand()%h;
		int r = rand()%50;
		rgb c = rgb{rand()%255, rand()%255, rand()%255};
		image.circle(x,y,r, c);
	}

	image.save(argv[1]);

	return 0;
}

