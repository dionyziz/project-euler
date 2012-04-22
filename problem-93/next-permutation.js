/////////////////////////////////////////////
// Permutation Generator
// - generate all permutation of given string 
//   array
// - Natthawut Kulnirundorn <m3rlinez at email by google>
//   http://www.solidskill.net 10 July 2011
/////////////////////////////////////////////

var PermutationGenerator = (function () {
    var self = {};

    // Get start sequence of given array
    self.getStartSequence = function (list) {
        return list.slice(0).sort();
    };

    // Get next sequence from given array
    // Ref: http://en.wikipedia.org/wiki/Permutation#Systematic_generation_of_all_permutations
    self.getNextSequence = function (list) {
        // Make clone
        var a = list.slice(0);

        //The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.
        //  1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
        var k = -1;
        for (var i = 0; i < a.length - 1; ++i) {
            if (a[i] < a[i + 1]) { k = i; }
        }
        if (k == -1) return null; // means this is the last one

        //  2. Find the largest index l such that a[k] < a[l]. Since k + 1 is such an index, l is well defined and satisfies k < l.
        var l = -1;
        for (var i = 0; i < a.length; ++i) {
            if (a[k] < a[i]) { l = i };
        }
        if (l == -1) return null; // impossible

        //  3. Swap a[k] with a[l].
        var tmp = a[k]; a[k] = a[l]; a[l] = tmp;

        //  4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
        var next = a.slice(0, k + 1).concat(a.slice(k + 1).reverse());

        return next;
    };

    return self;
} ());

module.exports = {
    permutationGenerator: PermutationGenerator
};
