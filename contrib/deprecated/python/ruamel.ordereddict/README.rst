
The ordereddict module in short
-------------------------------

This is an implementation of an ordered dictionary with Key Insertion
Order (KIO: updates of values do not affect the position of the key),
Key Value Insertion Order (KVIO, an existing key's position is removed
and put at the back). The standard library module OrderedDict, implemented
later, implements a subset of ``ordereddict`` functionality.

Sorted dictionaries are also provided. Currently only with Key Sorted
Order (KSO, no sorting function can be specified, but you can specify a
transform to apply on the key before comparison (e.g. string.lower)).

This package is hosted on BitBucket and installable from PyPI::

  pip install ruamel.ordereddict

For Windows there are 32 and 64 bit installable wheels available.

Usage::

  from ruamel.ordereddict import ordereddict
  kio = ordereddict()
  kvio = ordereddict(kvio=True)
  # without relax unordered initalisation is not allowed
  d = ordereddict({'a':1, 'b': 2}, relax=True)
  sd = sorteddict({'a':1, 'b': 2}) # sorteddict is always relaxed

**please note that starting with 0.4.6 you should not import _ordereddict
directly**

This module has been tested under:

=============  ========================= ==========
OS             compiler                  Python
Linux Mint 17  gcc 4.8.4                 2.7.13
Windows        Visual Studio 2010        2.7.13-32
Windows        Visual Studio 2010        2.7.13-64
=============  ========================= ==========

Older versions of this module has been tested under
and I expect those to still work:

=============  ========================  =========
OS             compiler                  Python
Windows XP-64  Visual Studio 2010        2.7.10-32
Windows XP-64  Visual Studio 2010        2.7.10-64
Windows XP-64  Visual Studio 2008        2.6.9-32
Windows XP-64  Visual Studio 2008        2.6.9-64
Linux Mint 17  gcc 4.8.2                 2.6.9
Ubuntu 12.04   gcc 4.7.2                 2.7.6
Ubuntu 12.04   gcc 4.7.2                 2.6.8
Ubuntu  8.04   gcc 4.2.4                 2.7.6
Ubuntu  8.04   gcc 4.2.4                 2.5.2
Windows XP     Visual C++ 2008 Express   2.7.6
Windows 7 64   Windows SDK for Win7 SP1  2.7.6
Ubuntu 12.04   gcc 4.6.3                 2.7.3
Ubuntu  8.04   gcc 4.2.4                 2.6.4
Ubuntu  8.04   gcc 4.2.4                 2.5.2
Ubuntu  8.10   gcc 4.3.2                 2.5.4
Ubuntu  8.10   gcc 4.3.2                 2.4.6
Ubuntu  7.04   gcc 4.1.2                 2.5.1
Ubuntu  7.04   gcc 4.1.2                 2.4.4
Ubuntu  6.06   gcc                       2.5.1
Windows XP     Visual Studio 2003        2.5.1
Windows XP     Visual C++ 2008 Express   2.6.5
Windows        MingGW 4.7.0              2.7.3
Solaris 10     GCC 4.4.x                 2.7.3
=============  ========================  =========

Version 0.4.1 was tested and found working on SuSE Linux Enterprise Server
(GCC 4.1.0 and Intel C/C++ 10.1) by Stuart Stock.

MingGW and Solaris were tested and reported to work by Wladimir with version
0.4.5

Home
----------------------------

https://bitbucket.org/ruamel/ordereddict is ordereddict's home on the web.

Clone the repository there if you want to work from the source.

http://www.xs4all.nl/~anthon/Python/ordereddict used to be
ordereddict's home on the web.
There you can still find the links for downloading the older version (0.4.5).



Installation
------------

.. comment: To install the package you can use::

   pip install ruamel.ordereddict

You can clone and checkout the sources, and then run::

   python setup.py install


Bugreporting
------------

If you find any problems, please let me know, but also realise that I
have a spamfilter that catches over 100 emails a day and yours might
get in there unnoticed. So if there is no response within a few days
please try again.

Functionality
-------------

ordereddict has all of the functionality of dict() except that there
is no keyword based initialisation and that you cannot pass a normal
dict to the initialisation of the basic ordereddict (however see the
relax-ed keyword below). sorteddict cannot be initialised from keywords
either, but can be initialised from normal dict (ie. they are always
relaxed).

As you probably would expect .keys(), .values(), .items(),
.iterkeys(), itervalues(), iteritems() and "for i in some_ordereddict"
have elements ordered based on the key insertion order (or key value
insertion order if kvio is specified, or sort order for sorteddict).

ordered/sorteddicts can be pickled.

Some methods have been slightly changed:

- initialisation of ordereddict takes keywords:

  - kvio: if set to True, then move an existing key on update
  - relax: if set to True, the ordereddict is relaxed for its life regarding
    initialisation and/or update from unordered data (read a normal dict).

- initialisation of sorteddict takes keyword:

  - key: specifies a function to apply on key (e.g. string.lower)

-  .popitem() takes an optional argument (defaulting to -1) indicating which
   key/value pair to return (by default the last one available)
- .dict()/.values()/.items()/.iterdict()/.itervalues()/.iteritems()
  all take an optional reverse (default False) parameter that gives
  the list reversed order resp. iterates in reverse
  (the non-iterator can also be done relatively efficient with e.g.
  od.dict().reverse() )
- .update(): takes an optional relax=True which allows one time
  ordereddict update from normal dictionaries regardless of
  initialisation time relax setting.

In addition to that ordereddict and sorteddict have some extra methods:

- .index(key) - gives an integer value that is the index of the key
- .setkeys()/.setvalues()/.setitems(), work like those in the Larosa/Foord
  implementation, although they might throw different exceptions:
  - setvalues' argument must be an itereable that returns the same number of
  items as the length of the ordereddict
  - setitems' argument is free in length, it performs a clear and adds
  the items in order.
- slice retrieval for all

and ordereddict only also has:

- .setkeys(), works like the one in the Larosa/Foord
  implementation. Argument must be an itereable returning a permutation of the
  existing keys ( that implies having the same length as the ordereddict)
- .reverse()  - reverses the keys in place
- .insert(position, key, value) - this will put a key at a particular position
  so that afterwards .index(key) == position, if the key was already there
  the original position (and value) is lost to the new position. This often
  means moving keys to new positions!
- slice deletion/assignment:
   - stepped deletion could be optimized a bit (individual items are deleted
     which can require memmoving multiple items)
   - assignment only from OrderedDict (with the same length as the slice). This
     could also be optimised as I first delete, then insert individual items.
     If the assigned items contain keys that are still there after the deletion
     'phase' then retrieving that slice does not always give the original
     assigned ordereddict (depending on the position of the items
     with those keys in either ordereddict)
- .rename(oldkey, newkey) renames a key, but keeps the items position and value

The new OrderedDict in the standard collections module
------------------------------------------------------

With Python 3.1 and backported to 2.7 there is an OrderedDict class
available in the collections modules. Raymond Hettinger indicated in
2009 at EuroPython that he preferred to start from a minimal
OrderedDict instead of using the Larosa/Foord
implementation. Unfortunately the available tests (for the
functionality that the simple collections.OrderedDict supports) were
not used either resulting in preventable bugs like repr initially not
working on recursive OrderedDicts.

ordereddict (and the Larosa/Foord implementation) is essentially
a superset of collections.OrderedDict, but there are a few
differences:

- OrderedDict is by default relax-ed.
- repr of recursive OrderedDict does not give any indication of the
  value of the recursive key, as it only displays `...`. ordereddict
  displays `ordereddict([...])` as value. Just using the dots like
  OrderedDict does is going to be ambiguous as soon as you have two different
  types A and B and nest A in B in A or B in B in A.
- some newer build-in functions available in OrderedDict are not
  available in ordereddict ( __reversed__, viewkeys, viewvalues, viewitems).

All of the differences can be straightened out in small (70 lines of
Python) OrderedDict wrapper around ordereddict. With this wrapper the
OrderedDict tests in the standard test_collections.py all pass.

Testing
-------

testordereddict.py in the test subdirectory has been used to test the module.
You can use::

  python testordereddict

to run the tests (py.test support has been dropped as newer versions
of py.test were not compatible).

There is a somewhat patched copy of the python lib/Test dictionary testing
routines included as well, it fails on the _update test however
because the default is not to use a relaxed ordereddict.
You can run it with::

  cd test/unit
  python test_dict.py

To Do
-----
- implement Value Sorted Order (VSO: specify value=True for normal
  value comparison), or a value rewrite function for VSO ( e.g.
  value=string.lower )
- implement Item Sorted Order (ISO): compare value then key ( the other way
  around would not make sense with unique keys, but we might have
  non-unique values).
- implement slice deletion for sorteddict
- more testing of sorteddict functionality
- speedtest slices
- speedtest sorteddict
- check on the test_update unittest in test_dict.py

To Consider
-----------
- comparing ordereddicts (as per Larosa/Foord)
- implement the whole (optionally) using pointers in the DictObject Items
  (Faster on insertion/deletion, slower on accessing slices, makes
  implementing algorithms somewhat more difficult), would have to seperate
  code for sorteddict as key position determination would be much slower.
- supply a pure Python implementation of exactly the functionality in
  ordereddict
- test on older versions (< 2.4) of Python and make portable (if this can
  be done without too much clutter) or port.
- test on the Mac
- optimise searching for an item pointer for sorteddict with binary search
  (for deletion)

Background information
----------------------

ordereddict is directly derived from Python's own dictobject.c file.
The extensions and the representation of ordereddicts() are based
on Larosa/Foord's excellent pure Python OrderedDict() module
(http://www.voidspace.org.uk/python/odict.html).

The implemenation adds a vector of pointers to elements to the basic
dictionary structure and keeps this vector compact (and in order) so
indexing is fast. The elements do not know about their position (so
nothing needs to be updated there if that position changes, but then
finding an item's index is expensive.  Insertion/deletion is also relatively
expensive in that on average half of the vector of pointers needs to
be memmove-d one position.
There is also a long value for bit info like kvio, relaxed.

The sorteddict structure has an additional 3 pointers of which only
one (sd_key) is currently used (the others are sd_cmp and sd_value).

Speed
-----

Based on some tests with best of 10 iterations of 10000 iterations of various
functions under Ubuntu 7.10 (see test/timeordereddict.py and test/ta.py)::

  Results in seconds:

  -------------------------------   dict         ordereddict  Larosa/Ford  collections
                                                              OrderedDict  OrderedDict
  empty                             0.023        0.025        0.023        0.024
  create_empty                      0.028        0.031        0.147        0.329
  create_five_entry                 0.037        0.042        0.384        0.558
  create_26_entry                   0.187        0.203        1.494        1.602
  create_676_entry                  5.330        5.574       36.797       34.810
  get_keys_from_26_entry            0.209        0.231        1.501        1.762
  pop_5_items_26_entry              0.219        0.247        1.952        1.864
  pop_26_items_676_entry            7.550        8.127       46.578       41.851
  popitem_last_26_entry             0.203        0.225        1.624        1.734
  popitem_last_676_entry            5.285        5.534       36.912       34.799
  popitem_100_676_entry          --------        5.552       36.577     --------
  walk_26_iteritems              --------        0.494        2.792        2.238
  -------------------------------   dict         ordereddict  Larosa/Ford  collections
                                                              OrderedDict  OrderedDict

  empty                             0.930     1.000           0.950        0.966
  create_empty                      0.909     1.000           4.728       10.594
  create_five_entry                 0.892     1.000           9.201       13.374
  create_26_entry                   0.923     1.000           7.368        7.901
  create_676_entry                  0.956     1.000           6.601        6.245
  get_keys_from_26_entry            0.908     1.000           6.508        7.641
  pop_5_items_26_entry              0.888     1.000           7.916        7.559
  pop_26_items_676_entry            0.929     1.000           5.732        5.150
  popitem_last_26_entry             0.901     1.000           7.222        7.712
  popitem_last_676_entry            0.955     1.000           6.670        6.288
  popitem_100_676_entry          --------     1.000           6.588     --------
  walk_26_iteritems              --------     1.000           5.653        4.532

Why
---

Because I am orderly ;-O, and because I use dictionaries to
store key/value information read from some text file quite often.
Unfortunately comparing those files with diff when written from
normal dictionaries often obfucates changes because of the reordering
of lines when key/value pairs are added and then written.

I have special routine for YAML files that takes lines like::

   - key1: val1
   - key2: val3
   - key3:
       - val3a
       - val3b

(i.e. a list of key-value pairs) directly to a single ordered dictionary
and back. (I find it kind of strange to finally have a structured,
human readeable, format that does not try to preserve the
order of key-value pairs so that comparing files is difficult with
'standard' text tools).

Older versions
--------------

http://www.xs4all.nl/~anthon/Python/ordereddict used to be
ordereddict's home on the web.

There you can still find the links for downloading the older version (0.4.5).


History
-------

``0.4.13``: 2017-0723
-

| ``0.4.9  2015-08-10``
| typos fixed by Gianfranco Costamagna
|
| ``0.4.8  2015-05-31``
| dependent on ruamel.base
| version number in a single place
| using py.test under tox
| generate wheel for 32/64bit py26/py27 on windows
|
| ``0.4.6  2014-01-18``
| Move to ruamel namespace, hosted on bitbucket, MIT License
| Testing with tox
|
| ``0.4.5  2012-06-17``
| Fix for a bug while inserting last item again beyond last position (reported
| by Volkan Çetin / volki tolki ( cetinv at gmail.com )
| Fix for repeated deletion and insertion fail. Found by and solution provided
| by Darren Dowker (including tests). Also found by Fabio Zadronzy (including
| a less elegant fix).
| applied reindent to .py and astyle to .c files
|
| ``0.4.3  2009-05-11``
| Fix for a bug in slicing SortedDicts.
| Found by, and fix provided by, Migel Anguel (linos.es)
|
| ``0.4.2  2009-03-27``
| Bug found and by Alexandre Andrade and Fabio Zadrozny in
| doing deepcopy
|
| ``0.4.1  2007-11-06``
| Bug found and fixed by Fabio Zadrozny on resizing dictionaries
|
| ``0.4   2007-10-30``
| added pickling, added relaxed initialisation/update (from unordered dicts)
| added KVIO (Key Value Insertion Order ie. key moves to back on update)
| implemented sorteddict, with KSO, Key Sorted Order. You can specify
| a function for key transformation before comparison (such as string.lower)
| sorteddict does not have all of the ordereddict methods as not all make
| sense (eg. slice assignment, rename, setkeys)
|
| ``0.3   2007-10-24``
| added setkeys/setvalues/setitems; slice retrieval, deletion, assignment
| .rename(oldkey, newkey) rename a key keeping same value and position
| .index() of non-existing key now returns ValueError instead of SystemError
| Changed the module name to _ordereddict (from ordereddict), as Jason
| Kirstland probably rightfully suggested that any private implementation
| likely has the (file)name ordereddict.py. A modulename with leading
| underscore seams more common for extension modules anyway.
|
| ``0.2a  2007-10-16``
| Solved the potential GC problem on Windows
|
| ``0.2   2007-10-16``
| First release, with some tests, and possible still a GC problem
| with Windows.
|
| ``0.1   2007-10-..``
| This version was never released. While testing it I was far in writing
| an email to comp.lang.python about why timing with timeit did seem to
| be memory hungry ....
| and then I realised ordereddict had a memory leak %-)
