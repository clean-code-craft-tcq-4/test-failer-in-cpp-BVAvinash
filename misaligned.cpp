#include <iostream>
#include <assert.h>

int GetPairNumber(int majorColor, int minorColor) {
    return (majorColor * 5 + minorColor + 1);
}

const char* getMajorColor(int majorColor, int minorColor, const char* majorColor[]) {       
    int pairNumber = getPairNumber(majorColor, minorColor);
    int majorColorFromPairNumber = (pairNumber - 1) / 5;
		
    return majorColor[majorColorFromPairNumber];
}	
const char* getMinorColor(int majorColor, int minorColor, const char* minorColor[]) {
    int pairNumber = getPairNumber(majorColor, minorColor);
    int minorColorFromPairNumber = pairNumber % 5;
		
    return minorColor[minorColorFromPairNumber];
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            
            assert(GetPairNumber(i, j) == (i*5+j)+1);
            assert(getMajorColor(i, j, majorColor) == majorColor[i]);
            assert(getMinorColor(i, j, minorColor) == minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
