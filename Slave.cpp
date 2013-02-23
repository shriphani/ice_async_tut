#include <Ice/Ice.h>
#include <Fibber.h>

using namespace std;
using namespace AsyncDemo;

int main(int argc, char* argv[]) {
	int status = 0;
	Ice::CommunicatorPtr ic;
	try {
		ic = Ice::initialize(argc, argv);
		Ice::ObjectPrx base = ic->stringToProxy("SimpleFibber:default -p 10000");
		FibberPrx fibber = FibberPrx::checkedCast(base);
		if (!fibber) {
			throw "Invalid Proxy";
		}
		Ice::AsyncResultPtr r = fibber->begin_fib(5);

		while (!r->isCompleted()) {
			cout << "Waiting" << endl;
		}
		cout << fibber->end_fib(r) << endl;
	} catch (const Ice::Exception& e) {
		cerr << e << endl;
		status = 1;
	} catch (const char* msg) {
		cerr << msg << endl;
		status = 1;
	}

	if (ic) {
		ic->destroy();
	}
	return status;
}