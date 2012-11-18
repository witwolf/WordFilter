import java.util.List;
public class WordFilter {
	
	private FSM fsm ;
	public WordFilter()
	{
		fsm = new FSM();
	}
	public void initFilterWithWords(List<String> words)
	{
		fsm.init(words);
	}
	public  String AfterFilter(String src)
	{
		char [] str = src.toCharArray() ;
		for(int index = 0 ; index < str.length  ; )
		{	
			fsm.nextState(Utils.toLowercase(str[index]));
			if(fsm.isEnd())
			{			
				String match = fsm.getMatch() ;
				for(int i = 0  ; i < match.length() ; i++)
				{
					str[index - i ] = '*' ;
				}
			}		
			index ++ ;
		}
		return new String(str);
	}
}
