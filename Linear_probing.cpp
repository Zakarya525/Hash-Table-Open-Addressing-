#include <iostream>
using namespace::std;

class Item{
	private:
		int data;
		
	public:
		Item(int d){
			data = d;
		}
		
		int getData(){
			return data;
		}
		
		void setData(){
			data = -1;
		}
	
};

class HashTable{
	private:
		Item* hashArray[10];
	
	public:
		HashTable(){
			for(int i = 0; i < 10; i++){
				hashArray[i] = new Item(-1);
			}
		}
		
		hashFunction(int data){
			return(data % 10);
		}
		
		void insert(Item* newElement){
			
			int value = newElement->getData();
			int hashValue = hashFunction(value);
			int probe = 0;
			while(hashArray[hashValue]->getData() != -1){
				
				hashValue++;
				probe++;
				hashValue %= 10;
			}
			
			hashArray[hashValue] = newElement;
			cout<<"Value "<<value<<" has been inserted after "<<probe<<" probes"<<" at index "<<hashValue<<endl;
		}
		
		Item* find(int key){
			
			int hashValue = hashFunction(key);
			while(hashArray[hashValue]->getData() != -1){
				
				if(hashArray[hashValue]->getData() == key){
					return hashArray[hashValue];
				}
				hashValue++;
				hashValue %= 10;
			}
			
			return NULL;
		}
		
		void deleteItem(int key){
			
			int hashValue = hashFunction(key);
			while(hashArray[hashValue]->getData() != -1){
				if(hashArray[hashValue]->getData() == key){
					int temp = hashArray[hashValue]->getData();
					hashArray[hashValue]->setData();
					cout<<"Value "<<temp<<" has been deleted, and slot set to "<<hashArray[hashValue]->getData()<<endl;
					return;
				}
				hashValue++;
				hashValue %= 10;
			}
			
			cout<<"Data not found"<<endl;
			
		}
};
int main(int argc, char** argv) {
	
	HashTable* table = new HashTable();
	table->insert(new Item(34));
	table->insert(new Item(33));
	table->insert(new Item(31));
	table->insert(new Item(64));
	table->insert(new Item(12));
	table->insert(new Item(14));
	table->insert(new Item(14));
	table->insert(new Item(14));
	table->insert(new Item(14));
	
	table->deleteItem(0);
	
	Item* value = table->find(63);
	if(value){
		cout<<value->getData()<<" Found";
	}
	else{
		cout<<"Not found";
	}
	
	
	
	return 0;
}
