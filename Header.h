#pragma once
#include <iostream>
using namespace std;

template < class T1, class T2>
class node
{
public:
	T1 EmpID;
	T1 CNIC;
	T1 JoiningDate;
	T2 Salary;
	T2 Bonus;
	node < T1, T2> *next;
	node < T1, T2> *prev;
	node(T1 id, T1 CNIC, T1 JoiningDate, T2 salary, T2 bonus)
	{
		this -> EmpID = id;
		this -> CNIC = CNIC;
		this -> JoiningDate = JoiningDate;
		this -> Salary = salary;
		this -> Bonus = bonus;
		next = NULL;
		prev = NULL;
	}
};

template < class T1, class T2>
class linkList
{
public:
	node< T1, T2>* head;
	node <T1, T2> *tail;
	linkList()
	{
		head = NULL;
		tail =NULL ;
	}

	void insert(T1 id, T1 CNIC, T1 JoiningDate, T2 salary, T2 bonus)
	{
		node<T1, T2>* temp = new node<T1, T2>(id, CNIC, JoiningDate, salary, bonus);
		if (head == NULL && tail == NULL)
		{
			head = temp;
			tail = temp;
			head->prev = tail;
			tail->next = head;
		}
		else
		{
			
			temp->prev = tail;
			tail->next = temp;
			
			tail = temp;
			head->prev = tail;
			tail->next = head;
		}
	}
	void search(T1 id) 
	{
		int count = 0;
		node<T1, T2>* p = head;
		if (head == NULL && tail == NULL)
		{
			cout << "list is empty" << endl;
		}
		else 
		{
			do 
			{
				count++;
				p = p->next;
				
			} while (p->EmpID != id && p != head);

			if (p->next == head)
			{
				cout << "not found" << endl;
			}
			else
			{
				cout << "id found at: " << count << endl;
			}
		}
	}
	void UpdateSalary(T1 id, T2 newSalary)
	{
		node<T1, T2>* p = head;
		if (head == NULL && tail == NULL)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			do
			{
				if (p->EmpID == id)
				{
					p->Salary = newSalary;
					break;
				}
				p = p->next;

			} while (p != head);
		}
	}
	T2 MaxSalary()
	{
		
		node<T1, T2>* p = head;
		T2 maxSalary = p->Salary;
		do
		{
			if (p->Salary > maxSalary)
			{
				maxSalary = p->Salary;
				
			}
			p = p->next;
		} while (p != head);
		return maxSalary;
	}
	void print()
	{
		node<T1, T2>* p = head;

		do
		{
			cout << "Employee id: " << p->EmpID << endl;
			cout << "CNIC: " << p->CNIC << endl;
			cout << "salary: " << p->Salary << endl;
			cout << "bonus: " << p->Bonus << endl;
			cout << "joining date: " << p->JoiningDate << endl;
			cout << "\t__________" << endl;
			p = p->next;
		} while (p != head);
	}
};
