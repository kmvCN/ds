#include <iostream>
#define MAX_SIZE 100

using namespace std;

template <class T>
class Queue
{
protected:
  T arr[MAX_SIZE];
  int front, rear, size;

public:
  Queue(int size = 100)
  {
    this->front = -1;
    this->rear = -1;
    this->size = size;
  }

  bool enqueue(T ele)
  {
    if (this->rear >= (this->size - 1))
    {
      cerr << "ERROR: Queue Filled\n";
      return false;
    }
    else if (this->isEmpty())
    {
      this->rear++;
      this->front++;
      this->arr[this->front] = ele;
    }
    else
      this->arr[++(this->rear)] = ele;
    return true;
  }
