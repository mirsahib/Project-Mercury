import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;


public class Huffman {
	public static class Node implements Comparable<Node>{
		char wd;
		int counter;
		Node(char c){
			wd = c;
			counter=1;
		}
		Node(char c,int f){
			wd = c;
			counter =f;
		}
		@Override
		public int compareTo(Node e) {
			if(this.counter>e.counter){
				return 1;
			}else if(this.counter<e.counter){
				return -1;
			}else{
				return 0;
			}
		}
		public String toString(){
			String s="Character: "+this.wd+"\nFrequency: "+this.counter;
			return s;
		}
	}
	public static void main(String[] args) {
		//String fileName = "text.txt";
		//@SuppressWarnings("unused")
		//HuffmanEncoder encode = new HuffmanEncoder(fileName);
		//encode.printCharList();
		//encode.printQueue();
		//encode.printTree();
		//writeFun();
		String str = "000010101011111111010011011";
		//byte [] byteStr =  str.getBytes();
		byte s= 0100;
		System.out.println("Success");
	}
	@SuppressWarnings("unused")
	private static void writeFun(){
		BufferedWriter bf = null;
		try {
			String Name = "encode.txt";
			File fileName = new File(Name);
			bf = new BufferedWriter(new FileWriter(fileName));
			bf.write("Hello World2");
		} catch (Exception e) {
			// TODO: handle exception
		}finally{
			try {
				bf.close();
			} catch (Exception e2) {
				// TODO: handle exception
			}
		}
		System.out.println("Success");
	}
}
