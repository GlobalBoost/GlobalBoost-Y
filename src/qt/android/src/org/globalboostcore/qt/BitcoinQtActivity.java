package org.globalboostcore.qt;

import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;

import org.qtproject.qt5.android.bindings.QtActivity;

import java.io.File;

public class GlobalBoostQtActivity extends QtActivity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        final File globalboostDir = new File(getFilesDir().getAbsolutePath() + "/.globalboost");
        if (!globalboostDir.exists()) {
            globalboostDir.mkdir();
        }

        super.onCreate(savedInstanceState);
    }
}
