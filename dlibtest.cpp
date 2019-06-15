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


    // Now print out how many dictionary vectors each center used.  Note that 
    // the maximum number of 8 was reached.  If you went back to the kcentroid 
    // constructor and changed the 8 to some bigger number you would see that these
    // numbers would go up.  However, 8 is all we need to correctly cluster this dataset.
    cout << "num dictionary vectors for center 0: " << test.get_kcentroid(0).dictionary_size() << endl;
    cout << "num dictionary vectors for center 1: " << test.get_kcentroid(1).dictionary_size() << endl;
    cout << "num dictionary vectors for center 2: " << test.get_kcentroid(2).dictionary_size() << endl;

}



