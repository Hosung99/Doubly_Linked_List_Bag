#pragma once
#include "Doubly_Linked_List.h"
#include <iostream>
using namespace std;

typedef size_t size_type; //양의 정수를 가리킬 type을 정의한다.

struct Node { //node라는 것을 정의할 클래스이다.
public:
	int data;  //data가 들어가는 변수이다.
	Node* next_ptr; //다음 노드를 가리킬 포인터이다.
	Node* prev_ptr; //이전 노드를 가리킬 포인터이다.
	Node() { //빈 노드 생성용이다.
		data = 0;
		next_ptr = nullptr;  //포인터는 NULL로 초기화시켜준다.
		prev_ptr = nullptr; //이전 포인터 또한 NULL로 초기화시킨다.
	};
	Node(int data) {
		this->data = data;  //노드에 data매개변수가 들어온다면 이 생성자를 실행시켜 데이터를 저장한다.
		next_ptr = nullptr;  //포인터는 NULL로 초기화시켜준다.
		prev_ptr = nullptr; //이전 포인터 또한 NULL로 초기화시킨다.
	};
	Node* link_next() { return next_ptr; }; //다음 포인터로의 이동를 의미한다.
	Node* link_prev() { return prev_ptr; }; //이전 포인터로의 이동를 의미한다.
	int data_return() { return data; };
};

int index;  //노드가 몇개인지 셀 변수이다

size_type list_length(Node* head_ptr) { //노드 개수를 리턴해주는 함수.
	size_t answer = 0; // 리턴할 개수를 저장하는 변수.
	Node* cursor; //헤드 포인터를 가리키고 계속 링크를 따라갈 포인터 선언.
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next_ptr) //for(초기:커서를 헤드포인터로잡아준다; 종결조건: 커서가 더이상 가리키는게없을때까지. NULL포인터; 증감식:커서는 다음링크를 따라간다.)
		++answer; //커서가 한개씩 옮겨질때마다 answer를 한개씩 올려준다.
	return answer; //length함수는 결국 node개수 리턴.
};

Node* list_search(Node* head_ptr, const int target) { //target값을 주면 그값에 맞는 포인터의 주소를 리턴해준다.
	Node* cursor=new Node(); //리스트를 찾아줄 커서 포인터를 선언.
	if (head_ptr == NULL)
		return NULL;
	for (cursor = head_ptr; cursor!=NULL; cursor=cursor->next_ptr){ //for(초기:커서를 헤드포인터로잡아준다; 종결조건: 커서가 더이상 가리키는게없을때까지. NULL포인터; 증감식:커서는 다음링크를 따라간다.)
		if (target == cursor->data) //target이 cursor의 data와 일치시 커서 주소 리턴.
			return cursor;
	}

	return NULL;//만약 for문안에서 안걸릴시 빈 포인터를 리턴.
};

Node* list_locate(Node* head_ptr, size_type& position) //위치를 알려주면 해당 위치의 포인터의 주소(인덱스)를 리턴해주는 함수.
{
	Node* cursor = head_ptr; //새로운 커서 선언후 헤드포인터로 초기화
	size_type i; //서치용 양의정수 i선언.
	for (i = 1; (cursor != NULL && i < position); i++) //for(초기: i=1. 종결조건: 커서가 NULL이아닐때. 즉 tail_ptr이 아닐때까지 and i가 찾는 위치
		cursor = cursor->next_ptr; //커서를 다음 노드로 옮긴다.
	return cursor;
};

void list_head_insert(Node*& head_ptr, int& entry) { //head부분에 새로 노드를 삽입 해주는 함수이다.
	Node* new_node = new Node; //새 노드 생성.
	new_node->data = entry; //data삽입
	new_node->next_ptr = head_ptr; //새노드의 다음을 현재 노드로설정
	new_node->prev_ptr = NULL; //새노드이므로 이전은 없다.
	head_ptr->prev_ptr = new_node; //현재 노드의 이전을 새노드로 설정.
	head_ptr = new_node; //새노드가 헤드가된다.
	index++; //노드가 늘었으므로 카운트를 1올린다.
};

void list_insert(Node* before,Node*& tail_ptr, int& insert) { //head가 아닌 부분에 새로운 노드삽입 함수이다. before 노드 뒤에 삽입할 것이다. 매개변수로 노드와 데이터가 필요하다. 리턴형식은 없다.
	Node* new_node = new Node(); //새로운 노드를 만든다.
	new_node->data = insert; //새로운 노드에 데이터를 삽입한다.
	if (index==1) //만약 인덱스가 1이거나 head_ptr이 1이면 head_insert함수로 넘긴다.
		list_head_insert(before,insert);
	else {
		new_node->next_ptr = before->next_ptr; //new 노드가 가리키는 다음포인터는 이전. before 가 가리키던 ptr이다.
		new_node->prev_ptr = before; //new노드가 가리키는 이전 포인터는 before이다.
		before->next_ptr->prev_ptr = new_node; //before가 가리키는 노드의 이전 포인터는 before를 가리켰지만. new_node를 향하게 한다.
		before->next_ptr = new_node; //before가 가리키던걸 new_node가 가리키게한다.
		index++; //노드가 늘었으므로 카운트를 1올린다.
	}
};

void list_head_remove(Node*& head_ptr) { //첫번째 노드를 지워주는 함수.
	Node* remove_ptr;
	remove_ptr = head_ptr; //remove_ptr가 첫번째 노드가됨.
	head_ptr = head_ptr->next_ptr; //헤드포인터가 두번째 노드를 가리키도록함.
	delete remove_ptr; //remove_ptr를 해제 시킨다. 
};

void list_remove(Node* previous_ptr) { //previous노드 다음의 노드를 삭제하는 함수이다.
	Node* remove_ptr; //제거할 노드와 같게맞출 노드 생성.
	remove_ptr = previous_ptr->link_next();  //제거할 노드(previous다음)를 설정한다.
	previous_ptr->next_ptr = remove_ptr->next_ptr;  //이전 노드의 다음 포인터는 remove할 노드가 가리키는 포인터이다.
	remove_ptr=remove_ptr->next_ptr; //제거할 노드를 다음 노드로 옮긴다.
	remove_ptr->prev_ptr = previous_ptr; //remove_ptr은 이제 previous의 다다음 노드이다. 그 상태에서 prev포인터를 previous를 향하게한다.
	delete remove_ptr; //remove 제거.
};

void list_clear(Node* head_ptr) { //모든 노드를 제거해주는 함수.
	while (head_ptr != NULL) { //head_ptr이 NULL이 아닐때까지 반복.
		list_head_remove(head_ptr);//head_ptr을 제거하는 함수를 한다.
	}
};

void list_copy(Node* source_ptr, Node*& head_ptr, Node*& tail_ptr) { //리스트를 복사하는 함수이다. 소스부분 부터 복사를 시작한다. 헤드,테일 포인터는 노드의 처음과 마지막을 가리킨다.
	if (source_ptr == NULL)   //처음이 NULL일시 복사할것이 없으므로 종료.
		return;

	list_head_insert(head_ptr,source_ptr->data); //첫 노드 생성.
	tail_ptr = head_ptr;  //노드가한개뿐이므로 헤드포인터와 테일포인터는 첫 노드를 가리킨다.
	source_ptr = source_ptr->next_ptr; //소스포인터를 다음으로 넘긴다.
	while (source_ptr != NULL) {
		list_insert(tail_ptr, tail_ptr,source_ptr->data);
		tail_ptr = tail_ptr->next_ptr;
		source_ptr = source_ptr->next_ptr;
	}
}; 

class Bag {

	private:
		Node* head_ptr = new Node;
		Node* tail_ptr = new Node;
		size_type many_nodes;
	public:
		Bag() { // 매개변수가 없을 때 기본 생성자.
			many_nodes = 0; //0으로 초기화해준다.
			head_ptr = tail_ptr;
			tail_ptr = head_ptr;
		};
		Bag(const Bag& source) { // 기본의 bag을 copy해서 새로운 bag을만들때 사용되는 생성자. copy constructor
			list_copy(source.head_ptr, head_ptr, tail_ptr); //list_copy함수를 실행한다.
			many_nodes = source.many_nodes; //노드의 수는 source노드의 노드의수로 맞춰준다.
		};
		~Bag() { //소멸자이다. 
			list_clear(head_ptr); //list_clear함수를 이용하여 모든 노드를 제거한다.
			many_nodes = 0; //노드가없어졌으니 노드의 수는 0이된다.
		};
		void insert(int entry) {  //Bag안에 자료를 넣어주는 함수.
			cout << "before insert" << endl;
			show_contents();
				list_head_insert(head_ptr,entry); //위치가상관없으므로 헤드insert함수를 호출해서 데이터를 넣는다.
				++many_nodes; //노드수가 1늘었으므로 1올려준다.
				cout << "after insert" << endl;
				show_contents();
				cout << endl;
		};
		void erase_one(int target) { //Bag안 target에 맞는 데이터를 없애주는 함수. 
			cout << "before erase" << endl;
			show_contents();
				Node* target_ptr;
				target_ptr = list_search(head_ptr, target); //타겟의 포인터를 찾는다.
				if (target_ptr == NULL) //타겟이 비었다면 실패.
					return;
				target_ptr->data = head_ptr->data; //헤드포인터가 가리키는 노드의 데이터를  타겟노드에 데이터를 넣는다.
				list_head_remove(head_ptr); //첫 노드를 지운다.
				--many_nodes;  //노드수가 하나줄었으므로 1내린다.
				cout << "after erase" << endl;
				show_contents();
				cout << endl;
		};
		void count(int target) { //target이 몇개인지 알려주는 함수.
			cout << "before count" << endl;
			show_contents();
			size_type answer = 0;
			Node* cursor; //search용 노드 선언. 
			cursor = list_search(head_ptr, target); //target을 찾는다.
			while (cursor != NULL) {
				++answer;
				cursor = cursor->next_ptr;
				cursor = list_search(cursor, target);
			}
			/*while (cursor != NULL) {
				++answer;
				cursor = cursor->next_ptr;
				cursor = list_search(head_ptr, target);
			}*/
			cout << endl;
			cout << target << " : " << answer << "개 있습니다." << endl;
			cout << "after count" << endl;
			show_contents();
		};
		friend Bag operator+(Bag & addend1, Bag & addend2) { // 가방 1과 가방2를 합치는 연산자. 
				Bag sum; //리턴할 bag선언
				sum += addend1;  //sum에 매개변수1가방을 합친다.
				sum += addend2; //sum에 매개변수2 가방을합친다.
				return sum; //매개변수1,2 가합쳐진 가방을 리턴한다.
		};
		void operator+=(const Bag & addend) { //가방에 연산자로+= 일시 기존에것들에 인자로 들어온 가방을 합쳐주는 함수.
				Node* copy_tail_ptr;
				Node* copy_head_ptr;

				if (addend.many_nodes > 0)
				{
					list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr); //함수를 복사한다. 매개변수로 들어온 노드의 헤드부터.
					copy_tail_ptr->next_ptr = head_ptr->next_ptr; //복사된 꼬리포인터가 가리키는 다음은 헤드포인터의 다음이다.
					head_ptr = copy_head_ptr;
					many_nodes += addend.many_nodes;
				}
		};
		void operator=(const Bag & source) { //두 가방을 같게 해주는 함수. 인자로들어오는 가방과 같게 해준다.
				Node* tail_ptr;

				if (this == &source) // 자기할당. 스스로를 복사하려는 건지 체크한다.
					return; //스스로 일시 함수 종료.
				list_clear(head_ptr); //모든 노드를 지운다.
				list_copy(source.head_ptr, head_ptr, tail_ptr); //source의 노드를 복사한다.
				many_nodes = source.many_nodes; //노드의 수는 source의 노드 수 이다
		};
		bool operator==(Bag & source) { //==연산자. 리턴으로 참,거짓을 준다.
				if (this == &source) { // 자기할당. 스스로를 복사하려는 건지 체크한다.
					return true;
				}
				else {
					head_ptr->link_next(); //헤드포인터를 다음포인터로 이동시킨다.
					while (head_ptr != NULL) { //head가 NULL 아닐때까지 다음 포인터로 이동한다.
						head_ptr->data_return() != source.head_ptr->data_return(); //헤드포인터가 가리키는노드의 데이터가 연산자로 들어오는 가방의 데이터와 불일치시 거짓이다.
						return false;
						head_ptr->link_next(); //헤드포인터를 다음 노드로 옮긴다.
					}
					return true;
				}
		};
		bool operator!=(Bag& source) { //가방간의 !=연산자. 달라야 true를 리턴한다. 깉을시 false리턴. ==연산자의 반대이다.
				if (this == &source) // 자기할당. 스스로를 복사하려는 건지 체크한다.
					return false;
				else {
					head_ptr->link_next(); //헤드포인터를 다음포인터로 이동시킨다.
					while (head_ptr != NULL) { //head가 NULL 아닐때까지 다음 포인터로 이동한다.
						head_ptr->data_return() != source.head_ptr->data_return(); //헤드포인터가 가리키는노드의 데이터가 연산자로 들어오는 가방의 데이터와 불일치시 거짓이다.
						return true;
						head_ptr->link_next(); //헤드포인터를 다음 노드로 옮긴다.
					}
					return false;
				}
		};
		void show_contents() {// 데이터를 보여주는 함수. 함수(operator도 포함) 시작과 끝에 넣어줘야한다.
			Node* new_node = head_ptr;
			if (new_node == NULL)  //헤드 다음이 비었을경우 출력
				cout << "Nothing in the Bag." << endl;
			else
				{
					cout << "The list is: ";
					while (new_node != NULL) //헤드가 안비었을경우 출력
					{
						cout << new_node->data<< " "; //현재노드의 data값출력.
						new_node = new_node->next_ptr;
					}
					cout << endl;
				};

		};
		void sort() { //오름차순 정렬 함수
			cout << "before sort" << endl;
			show_contents();
			Node* source_ptr = head_ptr;  //헤드포인터의 복사본생성.
			Node* save_ptr = NULL; //잠깐 저장하기위한 변수생성.

			int x = 0; //data 값을 바꾸기 위한 변수생성. 

			if (head_ptr == NULL) //만약 헤드가비었을경우엔 실행불가.
				return;

			while (source_ptr->next_ptr != NULL) { //2중 반복문. 헤드포인터부터시작해서 next로넘어가는데 NULL시 종료.
				save_ptr = source_ptr->next_ptr; //save는 헤드포인터의 다음이다.
				while (save_ptr != NULL) {  //save는 헤드포인터의 다음노드인데 next로넘어가서 null시 종료. 즉 source_ptr보다 일찍끝난다.
					if (source_ptr->data < save_ptr->data) { //save는 source의 다음 노드인데 다음 노드가 더 클시 밑에 코드 실행.
						x = source_ptr->data;  //값을 바꾸기위해 잠깐 저장.
						source_ptr->data = save_ptr->data; //source의 data대신 save의 data를 넣는다.
						save_ptr->data = x; //save의 data는 잠깐 저장해놓은 x로 넣는다.
					}
					save_ptr = save_ptr->next_ptr; //save를 다음노드로 넘긴다.
				}
				source_ptr = source_ptr->next_ptr; //source를 다음노드로 넘긴다.
			}


			cout << "after sort" << endl;
			show_contents();
		};


};
