import java.util.List;
import java.util.LinkedList;
public class WordFilterTest {
	public static void main(String args[])
	{
		String [] _words = 
			{
				"ababd",
				"fuck",
				"abc",
				"fuck you"
			};
		
		List<String> words = new LinkedList<String>();
		for(String word:_words)
		{
			words.add(word);
		}
		
		
		WordFilter wordFilter = new WordFilter();
		wordFilter.initFilterWithWords(words);
		
		String src = "ababc Fuck yo";
		String ret = wordFilter.AfterFilter(src);
		
		System.out.println("before filter : " + src);
		System.out.println("after filter : " + ret);
		
	}

}
