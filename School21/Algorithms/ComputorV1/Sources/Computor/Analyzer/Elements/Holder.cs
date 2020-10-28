namespace						Computor
{
	public class				Holder
	{
		public Element			Element
		{
			get;
			private set;
		}

		public bool				HasElement => Element == null; 
		
		public					Holder(Element element = null)
		{
			if (element != null)
				ConnectElement(element);		
		}

		public void				ConnectElement(Element newElement)
		{
			if (!HasElement)
				DisconnectElement();
			if (!newElement.HasHolder)
				newElement.DisconnectHolder();

			newElement.Holder = this;
			Element = newElement;
		}

		public Element			DisconnectElement()
		{
			Element				oldElement = Element;
			
			Element.Holder = null;
			Element = null;
			
			return oldElement;
		}

		public override string	ToString()
		{
			return Element != null ? Element.ToString() : "@";
		}
	}
}