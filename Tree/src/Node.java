
public class Node<T> {
	T data;
	Node<T> left;
	Node<T> right;
	
	Node(T item){
		data = item;
		left = null;
		right = null;
	}
}
