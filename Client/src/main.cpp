#include "EntryPoint.h"

EntryPoint* entryPoint;

int main()
{
	entryPoint->Init();
	
	entryPoint->Run();

	entryPoint->Shutdown();

	delete entryPoint;

	return 0;
}