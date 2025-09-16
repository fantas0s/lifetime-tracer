# lifetime-tracer
Simple classes to get debug trace of function lifetimes

## Overview
Let's start with this example function:

```
bool cumbersomeFunction()
{
    if (potentiallyHeavyOperation())
        return false;
    if (anotherPotentiallyHeavyOperation())
    {
        return yetAnotherHeavyOperation();
    }
    return false;
}
```

If one wants to find out how long it takes to execute this method, it'll need not only a timer, but also several checks on where the method was actually exited and timer reading from those.

Or then one can do this:

```
bool cumbersomeFunction()
{
    lifetime_tracer::Lifetimer timer;
    
    if (potentiallyHeavyOperation())
        return false;
    if (anotherPotentiallyHeavyOperation())
    {
        return yetAnotherHeavyOperation();
    }
    return false;
}
```

Which will automatically print out the time spent at the end of function, regardless of the path taken. The accuracy can be chosen between milliseconds and nanoseconds via constructor parameter.

If one wishes to trace a short function that is accessed frequently, more interesting value would be *cumulative measurement over several accesses*. For that there is the CumulativeLifetimer class, which is used insame manner, but it only does a print after certain amount of measurements have been taken. For that method the accuracy is always in nanoseconds. Amount of iterations to take before creating a printout can be set with the static method `setPrintInterval(quint64)`

Both classes are thread-safe.
