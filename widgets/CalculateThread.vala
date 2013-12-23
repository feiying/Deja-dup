/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 2 -*- */
using GLib;

namespace DejaDup {

public class CalculateThread : Object {
	public ThreadPriority priority { get; private set; }
	public int x_times { get; private set; }

	public CalculateThread (int times, ThreadPriority priority) {
		this.priority = priority;
		this.x_times = times;
	}

	public int run () {
		// set the priority:
		Thread.self<int> ().set_priority (ThreadPriority.URGENT);

		for (int i = 0; i < this.x_times; i++) {
			stdout.printf ("ping! %d/%d\n", i + 1, this.x_times);
			Thread.usleep (10000);
		}

		// return & exit have the same effect
		Thread.exit (42);
		return 43;
	}
}

}
