#ifndef LCDMenuItem_h
#define LCDMenuItem_h
#include <WString.h>

class LCDMenuItem{
	protected:
		LCDMenuItem* Prev;
		LCDMenuItem* Next;
		String Name;
	public:
		LCDMenuItem(String);
		void setPrev(LCDMenuItem *);
		void setNext(LCDMenuItem *);
		void (*action)();
		void setName(String);
		LCDMenuItem* getNext();
		LCDMenuItem* getPrev();
		String getName();
		unsigned int Timeout;
		
};

#endif