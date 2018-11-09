
public class BinarySearchTree<T extends Comparable<T>> {
	private Node root;
	
	BinarySearchTree() {
		root = null;
	}
	
	private Node insertElement(Node<T> root,T element){
		if(root == null){
			root = new Node(element);
			return root;
		}
		if(root.data.compareTo(element)>0){
			root.left = insertElement(root.left,element);
		}else if(root.data.compareTo(element)<0){
			root.right = insertElement(root.right,element);
		}
		return root; 
	}
	private void printElement(Node<T> root){
		if(root.left!=null){
			printElement(root.left);
		}
		System.out.print(root.data+" ");
		if(root.right!=null){
			printElement(root.right);
		}
	}
	private Node deleteElement(Node<T> root,T item){
		if(root==null){
			return root;
		}
		if(root.data.compareTo(item)>0){
			root.left = deleteElement(root.left,item);
		}else if(root.data.compareTo(item)<0){
			root.right= deleteElement(root.right,item);
		}
		else{
			if(root.left==null && root.right==null){
				root = null;
				return root;
			}else if(root.left==null){
				return root.right;
			}else if(root.right==null){
				return root.left;
			}else{
				T temp = findMin(root.right);
				root.right = deleteElement(root.right,temp);
			}
		}
		return root;
	}
	private T findMin(Node<T> temp){
		
		while(temp.left!=null){
			temp=temp.left;
		}
		return temp.data;
	}
	public void delete(T data){
		root = deleteElement(root,data);
	}
	public void min(){
		T temp = findMin(root);
		System.out.println(temp);
	}
	public void insert(T item){
		root = insertElement(root,item);
	}
	public void print(){
		printElement(root);
		System.out.println("\n");
	}
}
