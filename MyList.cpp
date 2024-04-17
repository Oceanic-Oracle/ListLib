#include <iostream>

namespace mylist
{
	template<typename T>
	class MyList 
	{
	public:
		MyList() 
		{
			this->_size = 0;
			this->head = nullptr;
		}
		~MyList()
		{
			while (this->head != nullptr)
			{
				this->pop_front();
			}
		}

		size_t size() 
		{
			return _size;
		}
		void push_back(T data) 
		{
			if(this->head == nullptr) 
			{
				this->head = new Knot(data);
			}
			else 
			{
				Knot* current = this->head;

				while (current->next != nullptr)
				{
					current = current->next;
				}

				current->next = new Knot(data);
			}
			this->_size++;
		}
		void pop_back()
		{
			if (this->head->next == nullptr)
			{
				delete this->head;
				this->head = nullptr;
				this->_size--;
			}
			else if (this->head != nullptr)
			{
				Knot* current = this->head;

				while (current->next->next != nullptr)
				{
					current = current->next;
				}
				delete current->next;
				current->next = nullptr;
				this->_size--;
			}
		}
		void push_front(T data)
		{
			if(this->head == nullptr)
			{
				this->head = new Knot(data);
			}
			else
			{
				Knot* temp = new Knot(data, this->head);
				this->head = temp;
			}
			this->_size++;
		}
		void pop_front() 
		{
			if (this->head != nullptr)
			{
				Knot* temp = this->head;
				this->head = this->head->next;
				delete temp;
				this->_size--;
			}
		}
		void print() 
		{
			if (head != nullptr)
			{
				Knot* current = this->head;
				std::cout << current->data;

				while (current->next != nullptr)
				{
					current = current->next;
					std::cout << current->data;
				}
			}
		}

	private:
		struct Knot
		{
			Knot(T data = T(), Knot* next = nullptr) : data(data), next(next) {}

			T data;
			Knot* next;
		};

		size_t _size;
		Knot* head;
	};
}