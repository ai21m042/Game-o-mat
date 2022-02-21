#include <stdio.h>

namespace GameOMat {

	__declspec(dllimport) void Print();

}

void main() {
	printf("Starting Sandbox\n");

	GameOMat::Print();

	printf("Ending Sandbox\n");
}