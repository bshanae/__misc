package org.bshanae.fixMe.tools.system;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class						AsyncExecutor
{
	private final ExecutorService	executorService;

	public							AsyncExecutor()
	{
		executorService = Executors.newCachedThreadPool();
	}

	public void 					execute(Runnable runnable)
	{
		executorService.execute(runnable);
	}

	public void 					terminate()
	{
		try
		{
			if (!executorService.awaitTermination(500, TimeUnit.MILLISECONDS))
				executorService.shutdownNow();
		}
		catch (InterruptedException ignored)
		{
			executorService.shutdownNow();
		}
	}
}
