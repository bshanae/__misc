namespace						Computor
{
	public class				Holder
	{
		private Element			_element;
		
		public Element			Element
		{
			get => _element;
			set
			{
				Error.Assert(_element == null || value == null);
				_element = value;
			}
		}

		public bool				IsEmpty => Element == null; 
		
		public					Holder(Element element = null)
		{
			Element = element;
		}

		public void				Place(Element element)
		{
			element.Place(this);
		}

		public void				Drop()
		{
			Element = null;
		}

		public override string	ToString()
		{
			return Element != null ? Element.ToString() : "@";
		}
	}
}