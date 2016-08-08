public class animalShelter {
	private MyQueue<dog> dogQueue = new MyQueue<dog>();
	private QueueNode<cat> catQueue = new MyQueue<cat>();
	public void enqueue(Animal animal){
		if (animal.type == AnimalType.DOG){
			enqueueDog((dog)animal);
		} else if (animal.type == AnimalType.CAT) {
			enqueueCat((cat)animal);
		}
	}

	public void enqueueDog(dog puppy){
		long time =  System.currentTimeMillis();
		dogQueue.add(puppy);
	}
	public void enqueueCat(cat kitten){
		long time =  System.currentTimeMillis();
		catQueue.add(kitten);
	}

	// public void dequeuAny(T animal){
	// 	return;
	// }
	// public void dequeDog(T dog){
	// 	return;
	// }
	// public void dequeDog(T cat){
	// 	return;
	// }
	public static void main(String[] args) {
        // Prints "Hello, World" to the terminal window.
        System.out.println("Hello, World");
    }
}

enum AnimalType {
	DOG, CAT
}

class Animal {
	private String name; 
	public int timeEnqueued;
	public AnimalType type;
	public void Animal(String name){
		this.name = name;
	}
}

class dog extends Animal {
	public void dog(String name){
		this.type = AnimalType.DOG;
	}
}

class cat extends Animal {
	public void cat(String name){
		this.type = AnimalType.CAT;
	}
}

class MyQueue<T> {
	class QueueNode<T> {
		private T data;
		private QueueNode<T> next;

		public QueueNode(T data){
			this.data = data;
		}
	}

	private QueueNode<T> first;
	private QueueNode<T> last;

	public void add(T item) {
		QueueNode<T> t = new QueueNode<T>(item);
		if (last != null) {
			last.next = t;
		}
		last = t;
		if (first == null) {
			first = last;
		}
	}

	public T remove() {
		//if (first == null) throw new NoSuchElementException();
		T data = first.data;
		first = first.next;
		if (first == null){
			last = null;
		}
		return data;
	}

	public T peek() {
		//if (first == null) throw new NoSuchElementException();
		return first.data;
	}

	public boolean isEmpty() {
		return first == null;
	}
}
