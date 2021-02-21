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
		
		void setData(int d){
			data = d;
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
		
		void insertQuardaticProbing(Item* newElement){
			
			int value = newElement->getData();
			int hashValue = hashFunction(value);
			int probe = 0;
			int step = 1;
			while(hashArray[hashValue]->getData() != -1){
				
				hashValue += step * step;
				probe++;
				hashValue %= 10;
				step++;
			
			}
			
			hashArray[hashValue] = newElement;
			cout<<"Value "<<value<<" has been inserted after "<<probe<<" probes"<<" at index "<<hashValue<<endl;
		}
		
		Item* find(int key){
			
			int hashValue = hashFunction(key);
			int step = 1;
			while(hashArray[hashValue]->getData() != -1){
				
				if(hashArray[hashValue]->getData() == key){
					return hashArray[hashValue];
				}
				hashValue += step * step;
				hashValue %= 10;
				step++;
			}
			
			return NULL;
		}
		
		void deleteItem(int key){
			
			int hashValue = hashFunction(key);
			int step = 1;
			while(hashArray[hashValue]->getData() != -1){
				if(hashArray[hashValue]->getData() == key){
					int temp = hashArray[hashValue]->getData();
					hashArray[hashValue]->setData(-1);
					cout<<"Value "<<temp<<" has been deleted, and slot set to "<<hashArray[hashValue]->getData()<<endl;
					return;
				}
				hashValue += step * step;
				hashValue %= 10;
				step++;
			}
			
			cout<<"Data not found"<<endl;
			
		}
};
int main(int argc, char** argv) {
	
	HashTable* table = new HashTable();
	table->insertQuardaticProbing(new Item(34));
	table->insertQuardaticProbing(new Item(33));
	table->insertQuardaticProbing(new Item(31));
	table->insertQuardaticProbing(new Item(64));
	table->insertQuardaticProbing(new Item(12));
	table->insertQuardaticProbing(new Item(14));
	table->insertQuardaticProbing(new Item(14));
	table->insertQuardaticProbing(new Item(14));
	table->insertQuardaticProbing(new Item(14));
	
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
