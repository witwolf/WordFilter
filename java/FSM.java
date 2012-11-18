
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.LinkedList;


public class FSM {

	private State start ;
	private State curState;

	public FSM()
	{
		start = new State(null,null ) ;
		curState = start;
	}

	public void init(List<String>  words)
	{
		for(String word:words)
		{
			State state = start ;
			for( int index = 0  ; index < word.length() ; index ++)
			{
				char lowercase = Utils.toLowercase(word.charAt(index)) ;
				state = insertState(state,lowercase);
			}
			state.match = word ;
			state.isEnd = true ;
		}

		Queue<State> states = new LinkedList<State>() ;
		states.add(start) ;
		while(!states.isEmpty())
		{
			State state = states.poll() ;
			initFailureState(state) ;
			for(State s : state.nexts.values() )
			{
				states.add(s) ;
			}	
		}	
	}

	public void nextState(char input)
	{
		Integer key = Integer.valueOf(input);
		if(curState.nexts.containsKey(key))
		{
			curState = curState.nexts.get(key);
			return;
		}
		else if(curState == start)
		{
			return;
		}
		else
		{
			curState = curState.failureState;
			nextState(input);
		}		
	}
	
	public boolean isEnd()
	{
		return curState.isEnd;
	}
	
	public String getMatch()
	{
		return curState.match;
	}

	private State insertState(State state,char input)
	{
		State ret;
		Integer key = Integer.valueOf(input);
		if(state.nexts.containsKey(key))
		{
			ret = state.nexts.get(key);
		}
		else
		{
			ret = new State(state,key);	
			state.nexts.put(key, ret);
		}		
		return ret;
	}
	private void initFailureState(State state)
	{
		if(state.prev == null || state.prev == start)
		{
			state.failureState = start;
		}
		else if(state.prev.failureState.nexts.containsKey(state.input))
		{
			state.failureState = state.prev.failureState.nexts.get(state.input);
		}
		else
		{
			state.failureState = start;
		}
	}
	class State
	{
		public Integer input ; 				
		public State prev ;						
		public Map<Integer,State> nexts;  
		public State failureState ;					
		public boolean isEnd ;						
		public String match ;						

		public State(State _prev,Integer _input)
		{
			nexts = new HashMap<Integer,State>() ;
			prev = _prev ;
			input = _input ;
			failureState = prev ;
			isEnd = false ;
			match = null ;
		}
	} 
}
