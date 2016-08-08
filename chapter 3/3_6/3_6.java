public class animalShelter {
	// public void enqueue(T animal){
	// 	return;
	// }
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


private class MyQueue<T> {
	private static class QueueNode<T> {
		private T data;
		private QueueNode<T> next;

		public QueueNode(T data){
			this.data = data;
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
}