/*
 *  Copyright (c) 2009 by Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 *
 * */

/*
 *  ======== Package.init ========
 *  Initialize this package.
 *
 *  This is called after all modules in this package are defined and
 *  initialized.
 */
function init()
{
//    print(this.$name + ".init() ...");
}

/*
 *  ======== Package.validate ========
 */
function validate()
{
    for (var i = 0; i < this.$modules.length; i++) {
        if (this.$modules[i].$used) {
            this.$modules[i].$logWarning("Module " + this.$modules[i].$name
                + " is used in this configuration. All modules from the"
                + " package 'ti.catalog.c470' should be replaced with modules"
                + " with the same name from the package 'ti.catalog.arm'",
                this);
        }
    }
}

/*
 *  ======== Package.exit ========
 *  Finalize this package
 *
 *  This is called after users configuration script completes but
 *  before generation.
 */
function exit() {
//    print(this.$name + ".exit() ...");
}

/*
 *  ======== Package.getLibs ========
 *  Get this package's libraries (This package's implementation of
 *  xdc.IPackage.getLibs)
 */
function getLibs()
{
    return (null);    /* no libraries for this package */
}
/*
 *  @(#) ti.catalog.c470; 1, 0, 1, 1,214; 12-9-2009 17:22:30; /db/ztree/library/trees/platform/platform-k27x/src/
 */

