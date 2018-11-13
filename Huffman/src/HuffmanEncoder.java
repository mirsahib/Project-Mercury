import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class HuffmanEncoder {
	private String line;
	private ArrayList<Node>charList;
	private ArrayList<Dictionary> dc;
	private PriorityQueue<Node>pq;
	private Node root;
	String binary;
	
	HuffmanEncoder(String file){
		//extracting line from the text file
		File fn = new File(file);
		try {
			@SuppressWarnings("resource")
			Scanner sc = new Scanner(fn);
			while(sc.hasNextLine()){
				line = sc.nextLine();
			}
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//extracting end
		charList = new ArrayList<Node>();//initializing charlist
		findFrequency();
		fillQueue();
		createHuffmanTree();//commented it when you want to run printQueue function
		binary = "";
		runDictionary();
		writeDictionary();
		encrypt();
	}
	//filling the priority queue with Node 
	//priority queue will arrange the Node according to it's frequency
	private void fillQueue(){
		this.pq = new PriorityQueue<Node>();
		for(int i=0;i<charList.size();i++){
			Node temp = charList.get(i);
			this.pq.add(temp);
		}
	}
	/*generating huffman tree
	algorithm:
		while(priority queue size is greater than 1){
			#extract the two minimum frequency node
			#add the frequency to node variable 'sum'  frequency
			#append the char and store to node vaiable 'sum' word
			#point the left and right arm of the sum variable to the two minimum frequency node
			#push node variable 'sum' to priority queue
		}
		#assignning root node as the head of the priority queue	
	*/
	private void createHuffmanTree(){
		while(pq.size()>1){
			Node temp1 = pq.remove();
			Node temp2 = pq.remove();
			Node sum = new Node();
			sum.freq = temp1.freq+temp2.freq;
			sum.word = temp1.word+""+temp2.word;
			sum.left = temp1;
			sum.right = temp2;
			pq.add(sum);
		}
		root = pq.remove();
	}
	//check how many time a character is present in the line
	private void findFrequency(){
		for(int i=0;i<line.length();i++){
			char c = line.charAt(i);//store ith character
			if(!inLine(c)){//check how many time the charachter is present in the arraylist
				Node temp = new Node(c);//create a node if character is not present
				charList.add(temp);//push the node to the arraylist
			}
		}
	};
	//check if a character is present in the list and return if it's true or false
	private boolean inLine(char c){
		boolean flag = false;
		for(int i=0;i<charList.size();i++){
			String x = Character.toString(c);
			if(x.equals(charList.get(i).word)){
				charList.get(i).freq++;
				flag = true;
			}
		}
		return flag;
	}
	//optional function
	//the function is used to show if the huffman tree is generated correctly 
	private void printTree(Node root){
		if(root.left!=null){
			printTree(root.left);
		}
		System.out.println(root);
		if(root.right!=null){
			printTree(root.right);
		}
	}
	/*	traverse the huffman tree and generate
		a binary code for corresponding character
		algorithm:
			# check if left node is available 
				#if available then push '0' in variable 'String bin'
			#check if right node is availabe 
				#if available then push '1' in variable 'String bin'
			#if the node is a leaf node 
				#then create a 'Dictionary temp' and push temp to arraylist
		exclude the last character of the String bin(stack suppose to do that but don't know why it stack don't exclude the last char)
		return String bin
	*/
	private String createDictionary(Node root,String bin,ArrayList<Dictionary> dc){
		if(root.left!=null){
			bin +="0";
			bin=createDictionary(root.left,bin,dc);
		}
		if(root.right!=null){
			bin+="1";
			bin=createDictionary(root.right,bin,dc);
		}
		if(root.left==null && root.right==null){
			Dictionary temp = new Dictionary();
			temp.word = root.word;
			temp.binary = bin;
			dc.add(temp);
		}
		bin = bin.substring(0,bin.length()-1);
		return bin;
	}
	//write the Dictionary arraylist to a file
	private void writeDictionary(){
		BufferedWriter writer = null;
		try {
			String name = "Dictionary.txt";
			File fileName = new File(name);
			writer = new BufferedWriter(new FileWriter(fileName));
			for(int i=0;i<dc.size();i++){
				String line = dc.get(i).word+" "+dc.get(i).binary+"\n";
				writer.write(line);
			}
		} catch (Exception e) {
			// TODO: handle exception
		}finally{
			try {
				writer.close();
			} catch (Exception e2) {
				// TODO: handle exception
			}
		}
	}
	//encrpytion function
	//eg: a is substituted as 001
	private void encrypt(){
		String encryptLine="";
		for(int i=0;i<line.length();i++){
			String ch = Character.toString(line.charAt(i));
			String cipherCode = cipher(ch);
			encryptLine+=cipherCode;
		}
		//to do: convert bit string into byte
		
		writeEncryptFile(encryptLine);
	}
	//write the encrypted string to a file
	private void writeEncryptFile(String line){
		BufferedWriter writer = null;
		try {
			String name = "encode.txt";
			File fileName = new File(name);
			writer = new BufferedWriter(new FileWriter(fileName));
			writer.write(line);
		} catch (Exception e) {
			// TODO: handle exception
		}finally{
			try {
				writer.close();
			} catch (Exception e2) {
				// TODO: handle exception
			}
		}
	}
	//return the binary code for the corresponding character
	//eg in the arraylist 'a=001' so the funtion will return '001'
	private String cipher(String ch){
		String s = "";
		for(int i=0;i<dc.size();i++){
			if(ch.equals(dc.get(i).word)){
				return dc.get(i).binary;
			}
		}
		return s;
	}
	//public function
	//optional function not needed for huffman
	public void printCharList(){
		for(int i=0;i<charList.size();i++){
			System.out.println(charList.get(i));
		}
	}
	public void printQueue(){
		while(!this.pq.isEmpty()){
			System.out.println(this.pq.remove());
		}
	}
	public void printTree(){
		printTree(root);
	}
	public void runDictionary(){
		dc = new ArrayList<Dictionary>();
		try{
			/*this function is inside a try catch because 
			it will return a 'stringoutofbound' error
			this is because of when i exclude the last char from the 'bin' variable
			at the root node 'bin' variable have no character in it
			so at the root node 'bin' is exluded for the last time and -1 is return
			which is out of bound
			*/
			createDictionary(root,binary,dc);
		}catch(Exception e){
			System.out.println(e);
		}
	}
}
