#include <iostream>
using namespace std;

class MusicalInstrument {
public:
	virtual void play() { cout << "Playing insturment ..." << endl; }
	virtual void reset() { cout << "Reseting insturment ..." << endl;  }
	virtual ~MusicalInstrument() {}
};


class Machine
{
public:
	virtual void start() { cout << "Starting machine ..." << endl; }
	virtual void reset() { cout << "Reseting machine ..." << endl; }
	virtual ~Machine() {}
};

class Synthesizer: public Machine, public MusicalInstrument
{
public:
	virtual ~Synthesizer() {}
};

int main() {

	Synthesizer *pnew = new Synthesizer();

	pnew->play();
	pnew->start();
	pnew->Machine::reset();

	delete pnew;

	return 0;
}