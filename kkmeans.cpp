#include <iostream>
#include <fstream>
#include <vector>

#include <dlib/clustering.h>
#include <dlib/rand.h>

using namespace std;
using namespace dlib;

int main()
{
	cout<<"Hello! :)"<<endl;

    typedef matrix<double,2,1> sample_type;
    typedef radial_basis_kernel<sample_type> kernel_type;

    kcentroid<kernel_type> kc(kernel_type(0.1),0.01, 8);
    kkmeans<kernel_type> test(kc);

    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;

    sample_type m;

    dlib::rand rnd;

    const long num = 200;

    // make some samples near the origin
    for (long i = 0; i < num; ++i)
    {
        m(0) = -100 + 200 * rnd.get_random_double();
        m(1) = -100 + 200 * rnd.get_random_double();

        samples.push_back(m);
    }

    test.set_number_of_centers(3);
    pick_initial_centers(3, initial_centers, samples, test.get_kernel());

    test.train(samples,initial_centers);

	ofstream fout("kkmeans_ex.txt", ios::out);
	for(auto m : samples) {
		fout<<m(0)<<"\t"<<m(1)<<"\t"<<test(m)<<endl;
	}
	fout.close();
}



