

#include "Assert.h"
#include "ObscuredInt.h"

#include <windows.h>


int main(int argc, char* argv[])
{
	//HMODULE module = LoadLibrary(L"D:\\\\svn_root\\\\NewSeason\\\\Bin\\\\Debug\\\\Common.dll");
	//ASSERT_C(nullptr != module, "nullptr for dll modules");
	
	//ASSERT_C(0, "hello world");

	int org_sample = 10;
	ObscuredTypes::ObscuredInt sample(10);

	printf("address: 0x%x, 0x%x", &sample, &org_sample);

	int result = sample;
	printf("sample: %d\n", result);

	sample = 20;

	printf("sample: %d\n", static_cast<int>(sample));

	return 0;
}