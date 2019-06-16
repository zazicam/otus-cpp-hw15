#include <iostream>
#include <fstream>
#include <vector>

#include <dlib/clustering.h>

using namespace dlib;

int main(int argc, char **argv)
{
	if(argc!=2) {
		std::cout<<"Error! Usage: "<<argv[0]<<" "<<"[number of clusters]"<<std::endl;
		exit(1);
	}

	int n = atoi(argv[1]); // number of clusters
	if(n<=1) {
		std::cout<<"Error! Incorrect number '"<<argv[1]<<"'"<<std::endl;
		std::cout<<"Need integer n >= 2"<<std::endl;
		exit(1);
	}

    typedef matrix<double,2,1> sample_type;
    typedef radial_basis_kernel<sample_type> kernel_type;

    kcentroid<kernel_type> kc(kernel_type(0.1),0.01, 8);
    kkmeans<kernel_type> test(kc);

    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;

	// read data
	char separator; // ;
    sample_type m;
	while(std::cin>>m(0)>>separator>>m(1)) {
		samples.push_back(m);
	}

	// learning
    test.set_number_of_centers(n);
    pick_initial_centers(n, initial_centers, samples, test.get_kernel());
    test.train(samples,initial_centers);

	// print results
	for(const auto& m : samples) {
		std::cout<<m(0)<<";"<<m(1)<<";"<<test(m)<<std::endl;
	}
}



