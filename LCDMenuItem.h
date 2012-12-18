#ifndef LCDMenuItem_h
#define LCDMenuItem_h
#include <WString.h>

class LCDMenuItem{
	protected:
		LCDMenuItem *Prev;
		LCDMenuItem *Next;
		String Name;
	public:
		LCDMenuItem(String);
		void setPrev(LCDMenuItem *);
		void setNext(LCDMenuItem *);
		LCDMenuItem* getNext();
		LCDMenuItem* getPrev();
		void setName(String);
		String getName();
		void (*action)();
};

#endif