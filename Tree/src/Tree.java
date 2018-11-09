
public class Tree {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinarySearchTree myTree = new BinarySearchTree();
		
		myTree.insert(12);
		myTree.insert(23);
		myTree.insert(15);
		myTree.insert(17);
		myTree.insert(10);
		myTree.print();
		myTree.delete(15);
		myTree.print();
		//System.out.println("hellow");
	}

}
