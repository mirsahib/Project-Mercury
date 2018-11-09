
public class Node implements Comparable<Node> {
	int freq;
	String word;
	Node left;
	Node right;
	Node(){};
	Node(char wd){
		freq = 1;
		word = ""+wd;
		left = null;
		right = null;
	}
	
	public int compareTo(Node e) {
		if(this.freq>e.freq){
			return 1;
		}else if(this.freq<e.freq){
			return -1;
		}else{
			return 0;
		}
	}

	public String toString(){
		String s = "Word "+this.word+" Freg "+this.freq;
		return s;
	}
}
