public class Data{
	//mostra il contenuto
	public void display(){
		sistem.print.out(this.data);	
	}

	public String data
	private String category;
	private int likes;

	//costruttore
	//se data = null lancia un'eccezione
	public Data(String data) throws NullPointerException{
		if(data == null){
			throw new NullPointerException();
		}
		this.category = null;
		this.data = data;
		this.likes = 0;
	}

	//assegna una categoria
	final public void assign_category(String cat) throws NullPointerException{
		if(cat == null){
			throw new NullPointerException();
		}
		this.category = new String(cat);
	}
	//aumenta il numero di like
	final public void add_like(){
		this.likes++;
	}
	final public get_data(String )
	//restituisce la categoria
	final public String category(){
		return category.clone();
	}
	//restituisce il numero di like
	final public int get_likes(){
		return this.likes;
	}

	//confrota il numero di like
	final public int compareTo(<E extends Data> data) throws NullPointerException{
		if(data == null){
			throw new NullPointerException();
		}
		return this.likes - data.likes;
	}
	//ritorna < 0 se l-argomento ha piu like
	//ritorna > 0 se l;argomento ha meno like
	//0 altrimenti
}