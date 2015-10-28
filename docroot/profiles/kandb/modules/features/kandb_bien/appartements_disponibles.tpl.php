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
        <div><?php print $row['superficie']; ?> m2</div>
        <div><?php print $row['etage']; ?></div>
        <div>
            <span><?php print $row['prix_5_5'] ; ?> € TVA 5,5%</span>
            <span><?php print $row['prix_20'] ; ?> € TVA 20%</span>
        </div>
    </div>    
    <?php endforeach; ?>
</div>