<?php
if(!isset($biens_rows) || empty($biens_rows)){
    return;
}
?>

<div>
    <?php foreach($biens_rows as $row) : ?>
    <div>
        <div><?php print $row['id']; ?></div>
        <div><?php print $row['caracteristiques']; ?></div>
        <div><?php if ($row['superficie']) { print $row['superficie'] . ' m2'; } ?></div>
        <div><?php print $row['etage']; ?></div>
        <div>
            <span><?php if ($row['prix_low_tva']['value'] && $row['prix_low_tva']['suffix']) { print $row['prix_low_tva']['value'] . ' ' . $row['prix_low_tva']['suffix']; } ?></span>
            <span><?php if ($row['prix_20']) { print $row['prix_20'] . ' € TVA 20%'; } ?></span>
        </div>
    </div>    
    <?php endforeach; ?>
</div>