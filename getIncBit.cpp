#include <iostream>
#include <vector>
using namespace std;

static int MAX_INT_SIZE  = 7;  // try 15
static int MAX_BIT_SIZE = 3;    // try 4

static int getIncBit_PreInit()
{
  static bool initialized = false;
  static size_t cur = 0;
  static vector<int> bitArr; //((MAX_INT_SIZE+1) * MAX_BIT_SIZE);

  if (!initialized)
  {
    // initialize the vector once, on the first call to this function
    initialized = true;

    for (int i = 0; i <= MAX_INT_SIZE; i++)
    {
      for (int j = MAX_BIT_SIZE -1; j >= 0; j--)
      {
        int mask = 1 << j;
        int insertVal = (i & mask) ? 1 : 0;
        bitArr.push_back(insertVal);
      }
    } 
  }

  int retVal = bitArr[cur];
  
  if (cur == bitArr.size() -1)
  {
    cur = 0;
  }
  else
  {
    cur++;
  }

  return retVal;
}

static int getIncBit_Dynamic()
{
  static int curInt = 0;
  static int curBit = MAX_BIT_SIZE - 1;

  int mask = 1 << curBit;
  int ret = curInt & mask ? 1 : 0;

  // increment for next time.
  if (curInt == MAX_INT_SIZE && curBit == 0)
  {
    curInt = 0;
    curBit = MAX_BIT_SIZE -1;
  }
  else if (curBit == 0)
  {
    curInt++;
    curBit = MAX_BIT_SIZE -1;
  }
  else 
  {
    curBit--;
  }

  return ret;
}

int main() {

  int max = (MAX_INT_SIZE + 1) * MAX_BIT_SIZE;

  for (int i = 0; i < max; i++)
  {
    cout << getIncBit_PreInit();

    if (i % MAX_BIT_SIZE == MAX_BIT_SIZE -1)
      cout << endl;
  }

  cout << endl << endl;

  for (int i = 0; i < max; i++)
  {
    cout << getIncBit_Dynamic();

    if (i % MAX_BIT_SIZE == MAX_BIT_SIZE -1)
      cout << endl;
  }

  return 0;
}
