#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

template <typename T>
class FullQueueExeption : public exception {
public:
	FullQueueExeption(T arg) : arg_(arg) {}
	T getNumber() { return arg_; }
private:
	T arg_;
};

class EmptyQueueException : public exception {
public:
	EmptyQueueException() {}
};

class IntRingBuffer
{
public:
	IntRingBuffer(void) :queue_start(0), queue_end(-1), actual_size(0) {}
	void enqueue(int a)
	{
			if (actual_size > 3)
				throw FullQueueExeption<int>(a);

			actual_size++;
			if (queue_end < 3) queue_end++; else queue_end = 0;
			queueArray[queue_end] = a;
	}
	int dequeue(void)
	{
			if (actual_size <= 0)
				throw EmptyQueueException();

			actual_size--;
			int old_queue_start = queue_start;
			if (queue_start < 3) queue_start++; else queue_start = 0;
			return queueArray[old_queue_start];
	}
private:
	int queueArray[4];
	int queue_start, queue_end, actual_size;
};

template <typename T, int size> 
class Queue
{
public:
	Queue(void) :queue_start(0), queue_end(-1), actual_size(0) {}
	void enqueue(T a)
	{
		if (actual_size >= size - 1)
			throw FullQueueExeption<T>(a);
		actual_size++;
		if (queue_end < size-1) queue_end++; else queue_end = 0;
		queueArray[queue_end] = a;
	}
	T dequeue(void)
	{
		if (actual_size <= 0)
			throw EmptyQueueException();
		actual_size--;
		int old_queue_start = queue_start;
		if (queue_start < size-1) queue_start++; else queue_start = 0;
		return queueArray[old_queue_start];
	}
private:
	T queueArray[size];
	int queue_start, queue_end, actual_size;
};




int main(void)
{
	IntRingBuffer iq;

	try{
		iq.enqueue(1);
		iq.enqueue(2);
		iq.enqueue(3);
		iq.enqueue(4);
		iq.enqueue(5);
		cout << iq.dequeue() << " ";
		cout << iq.dequeue() << " ";
		cout << iq.dequeue() << " ";
		cout << iq.dequeue() << endl;
	} 
	catch (FullQueueExeption<int> &e) {
		cout << "Exception catched : intQueue is full ! Element : " << e.getNumber() << " wasn't queued." << endl;
	}
	catch (EmptyQueueException&) {
		cout << "Exception catched : intQueue is empty !" << endl;
	}

	Queue<double,4> q;

	try
	{
		q.enqueue(1.3);
		q.enqueue(2.5);
		q.enqueue(3.1);
		q.enqueue(4.8);
		q.enqueue(5.4);
		cout << q.dequeue() << " ";
		cout << q.dequeue() << " ";
		cout << q.dequeue() << " ";
		cout << q.dequeue() << " " << endl;
	}
	catch (FullQueueExeption<double>& e) {
		cout << "Exception catched : Queue is full ! Element : " << e.getNumber() << " wasn't queued." << endl;
	}
	catch (EmptyQueueException&) {
		cout << "Exception catched : Queue is empty !" << endl;
	}

	Queue<string,4> qs;

	try{
		qs.enqueue("b");
		qs.enqueue("e");
		qs.enqueue("n");
		qs.enqueue("o");
		qs.enqueue("i");
		cout << qs.dequeue() << " ";
		cout << qs.dequeue() << " ";
		cout << qs.dequeue() << " ";
		cout << qs.dequeue() << " " << endl;
	}
	catch (FullQueueExeption<string>& e) {
		cout << "Exception catched : Queue is full ! Element : " << e.getNumber() << " wasn't queued." << endl;
	}
	catch (EmptyQueueException&) {
		cout << "Exception catched : Queue is empty !" << endl;
	}

	return 0;
}