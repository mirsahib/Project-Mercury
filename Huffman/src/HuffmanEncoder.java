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
		charList = new ArrayList<Node>();
		findFrequency();
		fillQueue();
		createHuffmanTree();//commented it when you want to run printQueue function
		binary = "";
		runDictionary();
		writeDictionary();
		encrypt();
	}
	private void fillQueue(){
		this.pq = new PriorityQueue<Node>();
		for(int i=0;i<charList.size();i++){
			Node temp = charList.get(i);
			this.pq.add(temp);
		}
	}
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
	private void findFrequency(){
		for(int i=0;i<line.length();i++){
			char c = line.charAt(i);
			if(!inLine(c)){
				Node temp = new Node(c);
				charList.add(temp);
			}
		}
	};
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
	private void printTree(Node root){
		if(root.left!=null){
			printTree(root.left);
		}
		System.out.println(root);
		if(root.right!=null){
			printTree(root.right);
		}
	}
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
	private void encrypt(){
		String encryptLine="";
		for(int i=0;i<line.length();i++){
			String ch = Character.toString(line.charAt(i));
			String cipherCode = cipher(ch);
			encryptLine+=cipherCode;
		}
		//convert bit string into byte
		
		writeEncryptFile(encryptLine);
	}
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
			createDictionary(root,binary,dc);
		}catch(Exception e){
			System.out.println(e);
		}
	}
}
