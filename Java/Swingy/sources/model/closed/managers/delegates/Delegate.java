package model.closed.managers.delegates;

import controller.open.Commands;
import model.closed.Game;
import model.closed.managers.delegates.common.ErrorDelegate;
import model.open.Model;
import model.open.Requests;

public abstract class			Delegate
{
// ---------------------------> Fields

	private boolean				isActivated;
	private boolean				isResolved;

	private boolean				isFirstTimeActivated;
	private boolean				isFirstTimeDeactivated;

	private Delegate			parentDelegate;
	private Delegate			childDelegate;

// ---------------------------> Constructor

	protected					Delegate()
	{
		isActivated = false;
		isResolved = false;

		isFirstTimeActivated = true;
		isFirstTimeDeactivated = true;
	}

// ---------------------------> Hierarchy methods

	public boolean				hasParent()
	{
		return parentDelegate != null;
	}

	public boolean				hasChild()
	{
		return childDelegate != null;
	}

	public void					linkParent(Delegate parentDelegate)
	{
		parentDelegate.checkHasNoChild();
		checkHasNoParent();

		parentDelegate.childDelegate = this;
		this.parentDelegate = parentDelegate;
	}

	protected void				unlinkParent()
	{
		checkHasParent();
		parentDelegate.checkHasChild();

		this.deactivate();
		parentDelegate.activate();

		parentDelegate.childDelegate = null;
		parentDelegate = null;
	}

	public void					linkChild(Delegate childDelegate)
	{
		checkHasNoChild();
		childDelegate.checkHasNoParent();

		this.childDelegate = childDelegate;
		childDelegate.parentDelegate = this;

		this.deactivate();
		childDelegate.activate();
	}

	protected void				unlinkChild()
	{
		checkHasChild();
		childDelegate.checkHasParent();

		childDelegate.deactivate();
		this.activate();

		childDelegate.parentDelegate = null;
		this.childDelegate = null;
	}

// ---------------------------> Control methods

	protected void				activate()
	{
		checkNotResolved();

		isActivated = true;
		whenActivated(isFirstTimeActivated);

		isFirstTimeActivated = false;
	}

	protected void				deactivate()
	{
		checkIfActivated();
		checkNotResolved();

		isActivated = false;
		whenDeactivated(isFirstTimeDeactivated);

		isFirstTimeDeactivated = false;
	}

	public final void			update()
	{
		checkNotResolved();

		if (childDelegate != null)
			childDelegate.update();

		if (isActivated)
			whenUpdated();
	}

	public final void			respond(Commands.Abstract command)
	{
		checkNotResolved();

		if (childDelegate != null)
			childDelegate.respond(command);

		if (isActivated)
			whenResponded(command);
	}

// ---------------------------> Resolution methods

	protected final void		resolve()
	{
		resolve(null);
	}

	protected final void 		resolve(Object message)
	{
		checkHasNoChild();
		checkIfActivated();

		if (hasParent())
		{
			Delegate			parentCopy = parentDelegate;

			unlinkParent();
			parentCopy.whenChildResolved(message);
		}

		isResolved = true;
	}

// ---------------------------> Verification methods

	private void				checkHasParent()
	{
		assert hasParent();
	}

	private void				checkHasNoParent()
	{
		assert !hasParent();
	}

	private void				checkHasChild()
	{
		assert hasChild();
	}

	private void				checkHasNoChild()
	{
		assert !hasChild();
	}

	private void				checkIfActivated()
	{
		assert isActivated;
	}

	private void				checkIfDeactivated()
	{
		assert !isActivated;
	}

	private void				checkNotResolved()
	{
		assert !isResolved;
	}

// ---------------------------> Callback methods

	protected void 				whenActivated(boolean isFirstTime) {}
	protected void 				whenDeactivated(boolean isFirstTime) {}

	protected void 				whenUpdated() {}

	protected void				whenResponded(Commands.Abstract command) {}

	protected void				whenChildResolved(Object message) {}

// ---------------------------> Helper methods

	protected boolean			validateCommand(Commands.Abstract command, Class<?> expectedClass)
	{
		if (!expectedClass.isAssignableFrom(command.getClass()))
		{
			linkChild(new ErrorDelegate("Unexpected command"));
			return false;
		}

		return true;
	}

	public boolean				tryRespondToCommonCommands(Commands.Abstract command)
	{
		if (command instanceof Commands.Exit)
			Game.getInstance().terminate();
		else
			return false;

		return true;
	}

	protected void				sendRequest(Requests.Abstract request)
	{
		Model.getInstance().notifyListener(request);
	}
}
