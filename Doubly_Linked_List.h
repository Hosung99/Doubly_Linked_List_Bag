#pragma once
#include "Doubly_Linked_List.h"
#include <iostream>
using namespace std;

typedef size_t size_type;

class Node { //node��� ���� ������ Ŭ�����̴�.
public:
	int data;  //data�� ���� �����̴�.
	Node* next_ptr; //���� ��带 ����ų �������̴�.
	Node* prev_ptr; //���� ��带 ����ų �������̴�.
	Node() { //�� ��� �������̴�.
		data = 0;
		next_ptr = NULL;  //�����ʹ� NULL�� �ʱ�ȭ�����ش�.
		prev_ptr = NULL; //���� ������ ���� NULL�� �ʱ�ȭ��Ų��.
	};
	Node(int data) {
		this->data = data;  //��忡 data�Ű������� ���´ٸ� �� �����ڸ� ������� �����͸� �����Ѵ�.
		next_ptr = NULL;  //�����ʹ� NULL�� �ʱ�ȭ�����ش�.
		prev_ptr = NULL; //���� ������ ���� NULL�� �ʱ�ȭ��Ų��.
	};
	Node* link_next() { return next_ptr; }; //���� �����ͷ��� �̵��� �ǹ��Ѵ�.
	Node* link_prev() { return prev_ptr; }; //���� �����ͷ��� �̵��� �ǹ��Ѵ�.
	int data_return() { return data; };
};

Node* head_ptr; //ù ��带 ����ų ����������̴�.
Node* tail_ptr; //������ ��带 ����ų �����������̴�.
int index;  //��尡 ����� �� �����̴�

class Doubly_Linked_List {
public:

	Doubly_Linked_List() { //�⺻������.
		head_ptr = new Node();  // ��������Ϳ� ���ο� ��带 �Ҵ��Ѵ�.
		tail_ptr = head_ptr; //��尡 �ϳ��̹Ƿ� tail�� ��带 ����Ų��.
		index = 0; // count�� 0���� �������ش�.
	};
	~Doubly_Linked_List() { //�Ҹ����̴�.
		Node* remove_ptr = head_ptr; //�����ϱ� ���� ���ο� ��带 �����, ��������Ͱ� ����Ű�°��� ����Ű���Ѵ�.
		delete head_ptr; //��������͸� ������Ų��.(���������Ͱ� �⸮Ű�Ƿ� ���̻� �ʿ�x)

		for (int i = 0; i < index; i++) {
			head_ptr = remove_ptr;
			remove_ptr = remove_ptr->link_next();
			delete head_ptr;
		}
	};
	size_type list_length(Node* head_ptr) { //��� ������ �������ִ� �Լ�.
	};
	Node* list_search(Node* head_ptr, int& target) { //target���� �ָ� �װ��� �´� �������� �ּҸ� �������ش�.
	};
	Node* list_locate(Node* head_ptr, size_type& position) //��ġ�� �˷��ָ� �ش� ��ġ�� �������� �ּ�(�ε���)�� �������ִ� �Լ�.
	{
	};
	void list_insert(Node* before, int& insert) { //head�� �ƴ� �κп� ���ο� ������ �Լ��̴�. before ��� �ڿ� ������ ���̴�. �Ű������� ���� �����Ͱ� �ʿ��ϴ�. ���������� ����.
	};
	void list_head_insert(Node* head_ptr, int& entry) { //head�κп� ���� ��带 ���� ���ִ� �Լ��̴�.
	};
	void list_head_remove(Node*& head_ptr) { //ù��° ��带 �����ִ� �Լ�.
	};
	void list_remove(Node* previous_ptr) { //previous��� ������ ��带 �����ϴ� �Լ��̴�.
	};
	void list_clear(Node* head_ptr) { //��� ��带 �������ִ� �Լ�.
	};
	void list_copy(Node* source_ptr, Node*& head_ptr, Node*& tail_ptr) { //����Ʈ�� �����ϴ� �Լ��̴�. �ҽ��κ� ���� ���縦 �����Ѵ�. ���,���� �����ʹ� ����� ó���� �������� ����Ų��.
	};
};
size_type list_length(Node* head_ptr) { //��� ������ �������ִ� �Լ�.
	size_t answer = 0; // ������ ������ �����ϴ� ����.
	Node* cursor; //��� �����͸� ����Ű�� ��� ��ũ�� ���� ������ ����.
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link_next()) //for(�ʱ�:Ŀ���� ��������ͷ�����ش�; ��������: Ŀ���� ���̻� ����Ű�°Ծ���������. NULL������; ������:Ŀ���� ������ũ�� ���󰣴�.)
		++answer; //Ŀ���� �Ѱ��� �Ű��������� answer�� �Ѱ��� �÷��ش�.
	return answer; //length�Լ��� �ᱹ node���� ����.
};
Node* list_search(Node* head_ptr, int& target) { //target���� �ָ� �װ��� �´� �������� �ּҸ� �������ش�.
	Node* cursor; //����Ʈ�� ã���� Ŀ�� �����͸� ����.
	for (cursor = head_ptr; cursor != nullptr; cursor->link_next()) {//for(�ʱ�:Ŀ���� ��������ͷ�����ش�; ��������: Ŀ���� ���̻� ����Ű�°Ծ���������. NULL������; ������:Ŀ���� ������ũ�� ���󰣴�.)
		if (target == cursor->data_return()) //target�� cursor�� data�� ��ġ�� Ŀ�� �ּ� ����.
			return cursor;
	}
	return NULL;//���� for���ȿ��� �Ȱɸ��� �� �����͸� ����.
};
Node* list_locate(Node* head_ptr, size_type& position) //��ġ�� �˷��ָ� �ش� ��ġ�� �������� �ּ�(�ε���)�� �������ִ� �Լ�.
{
	Node* cursor = head_ptr; //���ο� Ŀ�� ������ ��������ͷ� �ʱ�ȭ
	size_type i; //��ġ�� �������� i����.
	for (i = 1; (cursor != NULL && i < position); i++) //for(�ʱ�: i=1. ��������: Ŀ���� NULL�̾ƴҶ�. �� tail_ptr�� �ƴҶ����� and i�� ã�� ��ġ
		cursor = cursor->link_next(); //Ŀ���� ���� ���� �ű��.
	return cursor;
};

void list_head_insert(Node* head_ptr,int& entry) { //head�κп� ���� ��带 ���� ���ִ� �Լ��̴�.
	Node* new_node=new Node(entry);    //���ο� ��带 �����.
	new_node->next_ptr = head_ptr->next_ptr; //���ο� ��尡 ����Ű�°��� ��������Ͱ� ����Ű�� ���̴�.
	new_node->prev_ptr = NULL; //���ο� ����� ������ ����Ű�°��� ����.
	head_ptr->next_ptr = new_node;		//��������ʹ� ���ο� ������� ��带  ����Ų��.
	head_ptr->prev_ptr = NULL;          //����������� ������ ����Ű�°��� ����.
	index++; //��尡 �þ����Ƿ� ī��Ʈ�� 1�ø���.
};

void list_insert(Node* before, int& insert) { //head�� �ƴ� �κп� ���ο� ������ �Լ��̴�. before ��� �ڿ� ������ ���̴�. �Ű������� ���� �����Ͱ� �ʿ��ϴ�. ���������� ����.
	Node* new_node = new Node(); //���ο� ��带 �����.
	new_node->data = insert; //���ο� ��忡 �����͸� �����Ѵ�.
	if (index==1) //���� �ε����� 1�̰ų� head_ptr�� 1�̸� head_insert�Լ��� �ѱ��.
		list_head_insert(before, insert);
	else {
		new_node->next_ptr = before->next_ptr; //new ��尡 ����Ű�� ���������ʹ� ����. before �� ����Ű�� ptr�̴�.
		new_node->prev_ptr = before; //new��尡 ����Ű�� ���� �����ʹ� before�̴�.
		before->next_ptr->prev_ptr = new_node; //before�� ����Ű�� ����� ���� �����ʹ� before�� ����������. new_node�� ���ϰ� �Ѵ�.
		before->next_ptr = new_node; //before�� ����Ű���� new_node�� ����Ű���Ѵ�.
		index++; //��尡 �þ����Ƿ� ī��Ʈ�� 1�ø���.
	}
};


void list_head_remove(Node*& head_ptr) { //ù��° ��带 �����ִ� �Լ�.
	Node* remove_ptr;
	remove_ptr = head_ptr; //remove_ptr�� ù��° ��尡��.
	head_ptr = head_ptr->next_ptr; //��������Ͱ� �ι�° ��带 ����Ű������.
	head_ptr->prev_ptr = NULL; //��������Ͱ� ������ ����Ű�°� ����.
	delete remove_ptr; //remove_ptr�� ���� ��Ų��.
};
void list_remove(Node* previous_ptr) { //previous��� ������ ��带 �����ϴ� �Լ��̴�.
	Node* remove_ptr; //������ ���� ���Ը��� ��� ����.
	remove_ptr = previous_ptr->link_next();  //������ ���(previous����)�� �����Ѵ�.
	previous_ptr->next_ptr = remove_ptr->next_ptr;  //���� ����� ���� �����ʹ� remove�� ��尡 ����Ű�� �������̴�.
	remove_ptr->link_next(); //������ ��带 ���� ���� �ű��.
	remove_ptr->prev_ptr = previous_ptr; //remove_ptr�� ���� previous�� �ٴ��� ����̴�. �� ���¿��� prev�����͸� previous�� ���ϰ��Ѵ�.
	delete remove_ptr; //remove ����.
};
void list_clear(Node* head_ptr) { //��� ��带 �������ִ� �Լ�.
	while (head_ptr != NULL) { //head_ptr�� NULL�� �ƴҶ����� �ݺ�.
		list_head_remove(head_ptr);//head_ptr�� �����ϴ� �Լ��� �Ѵ�.
	}
};
void list_copy(Node* source_ptr, Node*& head_ptr, Node*& tail_ptr) { //����Ʈ�� �����ϴ� �Լ��̴�. �ҽ��κ� ���� ���縦 �����Ѵ�. ���,���� �����ʹ� ����� ó���� �������� ����Ų��.
	head_ptr = NULL;
	tail_ptr = NULL;
	if (source_ptr == NULL)   //ó���� NULL�Ͻ� �����Ұ��� �����Ƿ� ����.
		return;

	list_head_insert(head_ptr, source_ptr->data); //ù ��� ����.
	tail_ptr = head_ptr;  //��尡�Ѱ����̹Ƿ� ��������Ϳ� ���������ʹ� ù ��带 ����Ų��.
	source_ptr = source_ptr->link_next(); //�ҽ������͸� �������� �ѱ��.
	while (source_ptr != NULL) {
		list_insert(tail_ptr, source_ptr->data);
		tail_ptr = tail_ptr->link_next();
		source_ptr = source_ptr->link_next();
	}
};

class Bag {

	private:
		Node* head_ptr;
		size_type many_nodes;
	public:
		Bag() { // �Ű������� ���� �� �⺻ ������.
			head_ptr = NULL; // NULL�� �ʱ�ȭ���ش�.
			many_nodes = 0; //0���� �ʱ�ȭ���ش�.
		};
		Bag(const Bag& source) { // �⺻�� bag�� copy�ؼ� ���ο� bag�����鶧 ���Ǵ� ������. copy constructor
			Node* tail_ptr; //�Ű������� �ֱ����� �����Ѵ�.
			list_copy(source.head_ptr, head_ptr, tail_ptr); //list_copy�Լ��� �����Ѵ�.
			many_nodes = source.many_nodes; //����� ���� source����� ����Ǽ��� �����ش�.
		};
		~Bag() { //�Ҹ����̴�. 
			list_clear(head_ptr); //list_clear�Լ��� �̿��Ͽ� ��� ��带 �����Ѵ�.
			many_nodes = 0; //��尡���������� ����� ���� 0�̵ȴ�.
		};
		void insert(int entry) {  //Bag�ȿ� �ڷḦ �־��ִ� �Լ�,
				list_head_insert(head_ptr, entry); //��ġ����������Ƿ� ���insert�Լ��� ȣ���ؼ� �����͸� �ִ´�.
				++many_nodes; //������ 1�þ����Ƿ� 1�÷��ش�.
		};
		bool erase_one(int target) { //Bag�� target�� �´� �����͸� �����ִ� �Լ�. 
				Node* target_ptr;
				Doubly_Linked_List apply;  //�Լ� ������ ���� ��ü�� �ϳ������Ѵ�.
				target_ptr = list_search(head_ptr, target); //Ÿ���� �����͸� ã�´�.
				if (target_ptr == NULL) //Ÿ���� ����ٸ� ����.
					false;
				target_ptr->data = head_ptr->data; //����� �����͸�  Ÿ�ٳ�忡 �����͸� �ִ´�.
				list_head_remove(head_ptr); //��带 �����.
				--many_nodes;  //������ �ϳ��پ����Ƿ� 1������.
				return true;
		};
		size_type count(int target) { //target�� ����� �˷��ִ� �Լ�.
				size_t answer = 0;
				Node* cursor;
				cursor = list_search(head_ptr, target);
				while (cursor != NULL) {
					++answer;
					cursor = cursor->link_next();
					cursor = list_search(head_ptr, target);
				}
				return answer;
		};
		friend Bag operator+(Bag & addend1, Bag & addend2) { // ���� 1�� ����2�� ��ġ�� ������. 
				Bag sum; //������ bag����
				sum += addend1;  //sum�� �Ű�����1������ ��ģ��.
				sum += addend2; //sum�� �Ű�����2 ��������ģ��.
				return sum; //�Ű�����1,2 �������� ������ �����Ѵ�.
		};
		void operator+=(const Bag & addend) { //���濡 �����ڷ�+= �Ͻ� �������͵鿡 ���ڷ� ���� ������ �����ִ� �Լ�.
				Node* copy_tail_ptr;
				Node* copy_head_ptr;

				if (addend.many_nodes > 0)
				{
					list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr); //�Լ��� �����Ѵ�. �Ű������� ���� ����� ������.
					copy_tail_ptr->next_ptr = head_ptr->next_ptr; //����� ���������Ͱ� ����Ű�� ������ ����������� �����̴�.
					head_ptr = copy_head_ptr;
					many_nodes += addend.many_nodes;
				}
		};
		void operator=(const Bag & source) { //�� ������ ���� ���ִ� �Լ�. ���ڷε����� ����� ���� ���ش�.
				Node* tail_ptr;

				if (this == &source) // �ڱ��Ҵ�. �����θ� �����Ϸ��� ���� üũ�Ѵ�.
					return; //������ �Ͻ� �Լ� ����.
				list_clear(head_ptr); //��� ��带 �����.
				list_copy(source.head_ptr, head_ptr, tail_ptr); //source�� ��带 �����Ѵ�.
				many_nodes = source.many_nodes; //����� ���� source�� ��� �� �̴�
		};
		bool operator==(Bag & source) { //==������. �������� ��,������ �ش�.
				if (this == &source) { // �ڱ��Ҵ�. �����θ� �����Ϸ��� ���� üũ�Ѵ�.
					return true;
				}
				else {
					head_ptr->link_next(); //��������͸� ���������ͷ� �̵���Ų��.
					while (head_ptr != NULL) { //head�� NULL �ƴҶ����� ���� �����ͷ� �̵��Ѵ�.
						head_ptr->data_return() != source.head_ptr->data_return(); //��������Ͱ� ����Ű�³���� �����Ͱ� �����ڷ� ������ ������ �����Ϳ� ����ġ�� �����̴�.
						return false;
						head_ptr->link_next(); //��������͸� ���� ���� �ű��.
					}
					return true;
				}
		};
		bool operator!=(Bag& source) { //���氣�� !=������. �޶�� true�� �����Ѵ�. ������ false����. ==�������� �ݴ��̴�.
				if (this == &source) // �ڱ��Ҵ�. �����θ� �����Ϸ��� ���� üũ�Ѵ�.
					return false;
				else {
					head_ptr->link_next(); //��������͸� ���������ͷ� �̵���Ų��.
					while (head_ptr != NULL) { //head�� NULL �ƴҶ����� ���� �����ͷ� �̵��Ѵ�.
						head_ptr->data_return() != source.head_ptr->data_return(); //��������Ͱ� ����Ű�³���� �����Ͱ� �����ڷ� ������ ������ �����Ϳ� ����ġ�� �����̴�.
						return true;
						head_ptr->link_next(); //��������͸� ���� ���� �ű��.
					}
					return false;
				}
		};
		void show_contents() {// �����͸� �����ִ� �Լ�. �Լ�(operator�� ����) ���۰� ���� �־�����Ѵ�.
				/*Node* temp = head_ptr;
				temp = temp->link_next();
				std::cout << "Bag current:" << " ";
				while (temp != NULL)
				{
					std::cout << temp->data_return() << "  ";
					temp = temp->link_next();
				}
				*/
			cout << "Bag current :" << " " << endl;
		};
};