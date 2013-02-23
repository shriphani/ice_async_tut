#include <Ice/Ice.h>
#include <Fibber.h>

using namespace std;
using namespace AsyncDemo;

class FibberI : public Fibber {
public:
	virtual int fib(int n, const Ice::Current&);
};

int FibberI::fib(int n, const Ice::Current&) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int super_prev = 0;
	int prev = 1;
	int result = 0;

	for (int i = 2; i <= n; i++) {
		result = prev + super_prev;
		cout << result << endl;
		super_prev = prev;
		prev = result;
	}
	return result;
}


int main(int argc, char *argv[])
{
	int status = 0;
	Ice::CommunicatorPtr ic;
	try {
		ic = Ice::initialize(argc, argv); // initialize ic
		Ice::ObjectAdapterPtr adapter = 
			ic->createObjectAdapterWithEndpoints("SimpleFibberAdapter", "default -p 10000"); //
		Ice::ObjectPtr object = new FibberI;
		adapter->add(object, ic->stringToIdentity("SimpleFibber"));
		adapter->activate();
		ic->waitForShutdown();
	} catch (const Ice::Exception& e) {
		cerr << e << endl;
		status = 1;
	} catch (char* msg) {
		cerr << msg << endl;
		status = 1;
	}

	if (ic) {
		try {
			ic->destroy();
		} catch (const Ice::Exception& e) {
			cerr << e << endl;
			status = 1;
		}
	}
	return status;
}