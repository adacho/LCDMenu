#ifndef LCDMenuItem_h
#define LCDMenuItem_h
#include <WString.h>

class LCDMenuItem{
	protected:
		LCDMenuItem* Prev;
		LCDMenuItem* Next;
		String Name;
		void (*action)();
	public:
		LCDMenuItem(String);
		void setPrev(LCDMenuItem *);
		void setNext(LCDMenuItem *);
		void setName(String);
		void setAction(void (*newAction)());
		void executeAction();
		LCDMenuItem* getNext();
		LCDMenuItem* getPrev();
		String getName();
		unsigned int Timeout;
		
};

#endif